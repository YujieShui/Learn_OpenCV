'''
@Description: 模板匹配
@Author: shuiyj
@Date: 2019-07-26
'''
import cv2 as cv
import numpy as np

def template_demo():
    src = cv.imread("../images/llk.png")
    tpl = cv.imread("../images/llk_tpl.png")
    cv.imshow("input", src)
    cv.imshow("tpl", tpl)
    th, tw = tpl.shape[:2]
    result = cv.matchTemplate(src, tpl, cv.TM_CCORR_NORMED)
    cv.imshow("result", result)
    cv.imwrite("../images/039_001.png", np.uint8(result*255))
    t = 0.98
    loc = np.where(result > t)

    for pt in zip(*loc[::-1]):
        cv.rectangle(src, pt, (pt[0] + tw, pt[1] + th), (255, 0, 0), 1, 8, 0)
    cv.imshow("llk-demo", src)
    cv.imwrite("../images/039_002.png", src)

template_demo()
cv.waitKey(0)
cv.destroyAllWindows()