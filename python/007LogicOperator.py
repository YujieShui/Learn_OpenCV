'''
@Description: 像素的逻辑运算
@Author: shuiyj
@Date: 2019-07-23 17:21:28
@LastEditTime: 2019-07-23 18:59:13
'''
import cv2 as cv
import numpy as np

# create image src1
src1 = np.zeros(shape=[500, 500, 3], dtype=np.uint8)
src1[100:200, 100:200, 1] = 255
src1[100:200, 100:200, 2] = 255
cv.imshow("src1", src1)

# create image src2
src2 = np.zeros(shape=[500, 500, 3], dtype=np.uint8)
src2[150:250, 150:250, 1] = 255
cv.imshow("src2", src2)

# 逻辑运算
dst1 = cv.bitwise_and(src1, src2)
dst2 = cv.bitwise_or(src1, src2)
dst3 = cv.bitwise_xor(src1, src2)

cv.imshow("dst1", dst1)
cv.imshow("dst2", dst2)
cv.imshow("dst3", dst3)

# 取反操作
src = cv.imread("../images/1.png")
cv.namedWindow("src", cv.WINDOW_AUTOSIZE)
cv.imshow("src", src)
dst = cv.bitwise_not(src)

cv.imshow("dst", dst)

cv.waitKey(0)
cv.destroyAllWindows()