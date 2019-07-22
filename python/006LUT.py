import cv2 as cv

src = cv.imread("../images/2.jpg")
cv.namedWindow("src", cv.WINDOW_AUTOSIZE)
cv.imshow("src", src)
dst = cv.applyColorMap(src, cv.COLORMAP_COOL)
cv.imshow("dst", dst)

color_image = cv.applyColorMap(src, cv.COLORMAP_JET)
cv.imshow("color_image", color_image)

cv.waitKey(0)
cv.destroyAllWindows()