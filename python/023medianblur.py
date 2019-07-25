'''
@Description: 高斯模糊
@Author: shuiyj
@Date: 2019-07-25 18:47:42
'''
import cv2 as cv

src = cv.imread("../images/lena.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

dst1 = cv.medianBlur(src, 5)
dst2 = cv.medianBlur(src, 15)

cv.imshow("ksize=5", dst1)
cv.imshow("ksize=15", dst2)

cv.waitKey(0)
cv.destroyAllWindows()