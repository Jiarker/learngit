import numpy as np
import cv2 

img = cv2.imread("5.jpg")
points = []
key = 0#检测点的数量

def Event(event, x, y, flags, param):
    global key
    global points
    if event == cv2.EVENT_LBUTTONDOWN:
        xy = "%d,%d"%(x,y)
        
        #图像上表明观察点
        cv2.circle(img, (x,y),1,(255,0,0),thickness=-1)
        cv2.putText(img,xy,(x,y),cv2.FONT_HERSHEY_PLAIN,1.0,(0,0,0),thickness = 1)
        cv2.imshow("image",img)

        #存储各点
        points.append([x,y])
        
        #计算该点与上一点的距离
        if key != 0:
            distance = ((points[key-1][0]-points[key][0])**2 + (points[key-1][1]-points[key][1])**2) ** 0.5
            print(distance)
        
        key += 1


cv2.namedWindow("image")
cv2.setMouseCallback("image",Event)



while(1):
    cv2.imshow("image",img)
    if cv2.waitKey(0)&0xFF==27:
        break
cv2.waitKey(0)