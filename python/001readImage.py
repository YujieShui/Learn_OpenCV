'''
@Description: 读取一张图片
@Author: shuiyj
@Date: 2019-07-22 17:04:11
@LastEditTime: 2019-07-22 17:06:27
@LastEditors: Do not edit
'''
import cv2 as cv

src = cv.imread("../images/1.png")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)
cv.waitKey(0)
cv.destroyAllWindows()