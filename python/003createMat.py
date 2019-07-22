'''
@Description: 创建 Mat 的集中方法
@Author: shuiyj
@Date: 2019-07-19 10:09:24
@LastEditTime: 2019-07-22 17:07:16
@LastEditors: Do not edit
'''
import cv2 as cv
import numpy as np

src = cv.imread("../images/1.png")
cv.namedWindow("src", cv.WINDOW_AUTOSIZE)
cv.imshow("src", src)

# 克隆图像
m1 = np.copy(src)

# 赋值
m2 = src
src[100:200,200:300,:] = 255
cv.imshow("m2",m2)

m3 = np.zeros(src.shape, src.dtype)
cv.imshow("m3", m3)

m4 = np.zeros([512,512], np.uint8)
# m4[:,:] =127 try to give gray value 127
cv.imshow("m4", m4)

m5 = np.ones(shape=[512,512,3], dtype=np.uint8)
m5[:,:,0] = 255
cv.imshow("m5", m5)

cv.waitKey(0)
cv.destroyAllWindows()