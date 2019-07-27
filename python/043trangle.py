'''
@Description: TRIANGLE二值寻找算法
@Author: shuiyj
@Date: 2019-07-26 17:17:23
'''
import cv2 as cv
import numpy as np

src = cv.imread("../images/lena.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)
h, w = src.shape[:2]

# 自动阈值分割 TRIANGLE
gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
ret, binary = cv.threshold(gray, 0, 255, cv.THRESH_BINARY | cv.THRESH_TRIANGLE)
print("ret :", ret)
cv.imshow("binary", binary)

result = np.zeros([h, w*2, 3], dtype=src.dtype)
result[0:h,0:w,:] = src
result[0:h,w:2*w,:] = cv.cvtColor(binary, cv.COLOR_GRAY2BGR)
cv.putText(result, "input", (10, 30), cv.FONT_ITALIC, 1.0, (0, 0, 255), 2)
cv.putText(result, "binary, threshold = " + str(ret), (w+10, 30), cv.FONT_ITALIC, 1.0, (0, 0, 255), 2)
cv.imshow("result", result)

cv.waitKey(0)
cv.destroyAllWindows()