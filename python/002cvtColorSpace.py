'''
@Description: 颜色空间转换
@Author: shuiyj
@Date: 2019-07-22 17:06:38
@LastEditTime: 2019-07-22 17:06:39
@LastEditors: Do not edit
'''
import cv2 as cv

src = cv.imread("../images/1.png")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)
gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)
cv.waitKey(0)
cv.destroyAllWindows()