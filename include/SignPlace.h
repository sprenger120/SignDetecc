#ifndef SIGN_DETECC_SIGNPLACE_H
#define SIGN_DETECC_SIGNPLACE_H
#include <cv.h>

/**
 * Contains the region where a sign is placed in a training picture
 * and some helper functionality that aids in analyzing SignDetectors performance.
 */
class SignPlace {
public:
  SignPlace(const cv::Point& upperLeft, const cv::Point& lowerRight, const int signId);
  const cv::Point& getUpperLeft() const;
  const cv::Point& getLowerRight() const;
  const int getSignId() const;

  /**
   * Evaluates if the given SignPlace is overlapping enough
   * (Set by SIGN_PLACE_MIN_OVERLAPPING_PERCENTAGE) with this SignPlace
   * @return
   */
  const bool isOverlappingEnough(const SignPlace&);
private:
  /*
   upperLeft
   \/
   ******
   *    *
   *    *
   ******
   *    ^
   *    lowerRight
   */
  const cv::Point upperLeft;
  const cv::Point lowerRight;
  const int signId;
};


#endif //SIGN_DETECC_SIGNPLACE_H
