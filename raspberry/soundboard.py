import serial
import os
from pygame import mixer

def playSound(aSoundFile):
    print('playing ' + aSoundFile)
    mixer.music.stop()
    mixer.music.load(getFilePath(aSoundFile))
    mixer.music.play()

def getFilePath(aFilePath):
    return os.path.join(os.path.dirname(__file__), aFilePath)

sounds = []
sounds.append('sound/weggeflankt.mp3')
sounds.append('sound/weggeflankt.mp3')
sounds.append('sound/weggeflankt.mp3')
sounds.append('sound/weggeflankt.mp3')
sounds.append('sound/weggeflankt.mp3')
sounds.append('sound/weggeflankt.mp3')
mixer.init()

serial = serial.Serial("/dev/ttyUSB0", 9600)

while 1:
    serial_input = str(serial.readline(), 'UTF-8').rstrip('\r\n')
    if (serial_input.startswith'Sound-'):
        sound_index = int(serial_input[6:])
        if (sound_index < len(sounds)):
            playSound(sounds[sound_index])