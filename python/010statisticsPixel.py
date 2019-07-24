'''
@Description: 像素值统计
@Author: shuiyj
@Date: 2019-07-24 10:55:48
@LastEditTime: 2019-07-24 11:11:48
'''
import cv2 as cv
import numpy as np

src = cv.imread("../images/1.png")
cv.namedWindow("src", cv.WINDOW_AUTOSIZE)
cv.imshow("src", src)

gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
min, max, minLoc, maxLoc = cv.minMaxLoc(gray)
print("min: %.2f, max: %.2f"% (min, max))
print("min loc: ", minLoc)
print("max loc: ", maxLoc)

means, stddev = cv.meanStdDev(gray)
print("mean: %.2f, stddev: %.2f"% (means, stddev))
src[np.where(src < means)] = 0
src[np.where(src > means)] = 255
cv.imshow("binary", src)

cv.waitKey(0)
cv.destroyAllWindows()