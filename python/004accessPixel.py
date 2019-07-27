'''
@Description: OpenCV 遍历图像
@Author: shuiyj
@Date: 2019-07-27 13:58:34
'''
import cv2 as cv

src = cv.imread("../images/1.png")
cv.namedWindow("input", cv.WINDOW_AUTOSIZE)
cv.imshow("input", src)
h, w, ch = src.shape
print("h , w, ch", h, w, ch)
for row in range(h):
    for col in range(w):
        b, g, r = src[row, col]
        b = 255 - b
        g = 255 - g
        r = 255 - r
        src[row, col] = [b, g, r]
cv.imshow("output", src)

cv.waitKey(0)
cv.destroyAllWindows()