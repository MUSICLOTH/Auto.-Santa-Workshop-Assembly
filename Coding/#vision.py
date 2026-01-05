#vision.py
import cv2
import serial 
import time

ser = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        continue

hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

red_mask = cv2.inRange(hsv, (0,120,70), (10,255,255))
green_mask = cv2.inRange(hsv, (40,70,70), (80,255,255))
black_mask = cv2.inRange(hsv, (0,0,0), (180,255,40))

red_pixels = cv2.countNonZero(red_mask)
green_pixels = cv2.countNonZero(green_mask)
black_pixels = cv2.countNonZero(black_mask)

if red_pixels > 3000:
    ser.write(b'R/n')
    print("RED detected")
    time.sleep(1)

elif green_pixels > 3000:
    ser.write(b 'G/n')
    print("GREEN detected")

elif black_pixels > 3000:
    ser.write(b 'B/n')
    print("BLACK detected")
    time.sleep(1)

cv2.imshow("Vision", frame)
if cv2.waitKey(1) & 0xFF == ord('q'):
    break

cap.release()
cv2.destroyAllWindows()
