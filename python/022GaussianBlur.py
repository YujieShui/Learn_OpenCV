'''
@Description: 高斯模糊
@Author: shuiyj
@Date: 2019-07-25 18:47:42
'''
import cv2 as cv

src = cv.imread("../images/lena.jpg")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)

dst1 = cv.GaussianBlur(src, (5, 5), sigmaX=15)
dst2 = cv.GaussianBlur(src, (0, 0), sigmaX=15)

cv.imshow("gaussian ksize=5", dst1)
cv.imshow("gaussian sigmax=15", dst2)

cv.waitKey(0)
cv.destroyAllWindows()