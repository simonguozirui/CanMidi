#Parse MIDI files into something for servos

import serial
import time
from mido import MidiFile

def tick2ms (ticks):
    if ticks == 0:
        return 0
    return 1000*ticks/192

def ParseTrack(track):
    returnTrack = []
    for message in track:
        if message.type == 'note_off':
            returnTrack.append(tick2ms(message.time))
    return returnTrack

def NewMIDIRead (channels, mid):
    tracks = []

    print("Length (s): " + str(mid.length))

    for i, track in enumerate(mid.tracks):

        onoffTrack = ParseTrack(track)
        if not onoffTrack:
            continue
        tracks.append(onoffTrack)

        # print('Track {}: {}'.format(i, track.name))
        # print('Off Times: {}'.format(onoffTrack))

    return tracks

ser = serial.Serial("/dev/tty.usbmodem1411")

channels = 8
fileName = "Test1Scale.mid"

mid = MidiFile(fileName)
mid.type = 1

while True:

    channelInput = NewMIDIRead(channels, mid)
    current16Beat = 0

    print ("97")
    ser.write(b'a')

    while True:
        channelWrite = [0 for i in range(channels)]
        count = 0
        for channel in channelInput:
            if len(channel) <= 1:
                continue
            if channel[0] == current16Beat*250:
                channelWrite[count] = 1
                channel[1] += channel[0]
                channel.pop(0)

            count += 1

        ser.write(channelWrite)

        print(channelWrite)

        current16Beat += 1

        if (current16Beat*250) >= (mid.length * 1000):
            break

    print ("End Loop! Looping...")

