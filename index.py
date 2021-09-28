import cv2
import serial
import time
from handtrackingmodule import handDetector
ard = serial.Serial('/dev/ttyACM0',9600 , serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)
def getValue(ls):
    value= "".join(map(str,ls))
    lol=bytes(value.encode())
    time.sleep(1)
    ard.write(lol)

detector = handDetector(detectionCon=0.75)
cap = cv2.VideoCapture(0)
tipid = [8, 12, 16, 20]
kl=0
while True:
    x, img = cap.read()
    img = detector.findHands(img)
    imlist = detector.findPosition(img, draw=False)
    print(len(imlist))
    if len(imlist) != 0:
        kk = []
        if imlist[4][1] > imlist[5][1]:
            kk.append(1)
        else:
            kk.append(0)
        for i in range(4):
            if imlist[tipid[i]][2] < imlist[tipid[i]-2][2]:
                kk.append(1)
            else:
                kk.append(0)
        #print(kk)
        if kk!=kl:
            getValue(kk)
            print("kl")
        kl=kk
        fkk = str(kk.count(1))
        cv2.putText(img, fkk, (10, 300),
                    cv2.FONT_HERSHEY_SIMPLEX, 4, (10, 100, 200))
    cv2.rectangle(img, (0, 200), (150, 350), (255, 7, 55), 3)

    cv2.imshow("frm1", img)
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break
cap.release()
cv2.destroyAllWindows()
