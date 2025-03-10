// From https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=1017348
#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <cassert>

int main(int argc, char** argv)
{

  std::vector<cv::Point> pts;

  pts.push_back(cv::Point(3,100));
  pts.push_back(cv::Point(5,98));
  pts.push_back(cv::Point(6,110));

  cv::Rect rect = cv::boundingRect(pts);

  std::cout << "x: " << rect.x << "+" << rect.width
            << "   y: " << rect.y << "+" << rect.height
            << "\n";
  assert(rect.x == 3);
  assert(rect.width == 4);
  assert(rect.y == 98);
  assert(rect.height == 13);
}
