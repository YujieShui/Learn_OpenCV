'''
@Description: 算数运算
@Author: shuiyj
@Date: 2019-07-27 14:55:32
'''
import cv2 as cv
import numpy as np

src1 = cv.imread("../images/1.png")
src2 = cv.imread("../images/2.jpg")

cv.imshow("input1", src1)
cv.imshow("input2", src2)

# 图像的数据类型、通道数目、大小必须相同
src2 = cv.resize(src2, (src1.shape[1], src1.shape[0]))

h, w, ch = src1.shape
print("h , w, ch", h, w, ch)

h, w, ch = src2.shape
print("h , w, ch", h, w, ch)

add_result = np.zeros(src1.shape, src1.dtype)
cv.add(src1, src2, add_result)
cv.imshow("add_result", add_result)

sub_result = np.zeros(src1.shape, src1.dtype)
cv.subtract(src1, src2, sub_result)
cv.imshow("sub_result", sub_result)

mul_result = np.zeros(src1.shape, src1.dtype)
cv.multiply(src1, src2, mul_result)
cv.imshow("mul_result", mul_result)

div_result = np.zeros(src1.shape, src1.dtype)
cv.divide(src1, src2, div_result)
cv.imshow("div_result", div_result)

cv.waitKey(0)
cv.destroyAllWindows()