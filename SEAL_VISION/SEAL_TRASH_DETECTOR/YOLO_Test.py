#!/usr/bin/env python3 

import cv2
import numpy as np
import pyzed.sl as sl
from ultralytics import YOLO


# --- ZED setup ---
zed = sl.Camera()


init_params = sl.InitParameters()
init_params.camera_resolution = sl.RESOLUTION.HD720
init_params.camera_fps = 60
init_params.depth_mode = sl.DEPTH_MODE.NONE


if zed.open(init_params) != sl.ERROR_CODE.SUCCESS:
   print("Camera open failed. Exit.")
   exit()


runtime = sl.RuntimeParameters()
img_left = sl.Mat()
img_right = sl.Mat()



# YOLO Stuff
trt_model = YOLO("best_mk2.pt")

cap = cv2.VideoCapture(0)

while cap.isOpened():
   success, frame = cap.read()

   if not success:
      break
   results = trt_model("frame")

   plotted_frame = results[0].plot()

   cv2.imshow("YOLOv11 TensorRT SEAL MK2", plotted_frame)
   if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()



