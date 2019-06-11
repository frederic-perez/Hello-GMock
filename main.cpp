// --

#include <iostream>

#include <gmock/gmock.h>

// Code based on
// https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md

class Turtle {
public:
  virtual ~Turtle() {}
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};

class MockTurtle : public Turtle {
public:
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD1(Forward, void(int distance));
  MOCK_METHOD1(Turn, void(int degrees));
  MOCK_METHOD2(GoTo, void(int x, int y));
  MOCK_CONST_METHOD0(GetX, int());
  MOCK_CONST_METHOD0(GetY, int());
};

int
main()
{
  std::cout << "Hello, GMock!" << std::endl;

  using namespace testing;
  // The following line causes Google Mock to throw an exception on failure,
  // which will be interpreted by your testing framework as a test failure.
  //
  // GTEST_FLAG(throw_on_failure) = true;
  // InitGoogleMock(&argc, argv);

  MockTurtle mock_turtle;
  std::cout << "mock_turtle:\n";
  // ON_CALL(mock_turtle, GetX()).WillByDefault(Return(-1));
  EXPECT_CALL(mock_turtle, GetX())
    .Times(AtLeast(2))
    .WillOnce(Return(42))
    .WillOnce(Return(66))
    .WillRepeatedly(Return(-1));
  for (size_t i = 0; i < 4; ++i)
    std::cout << "  x=" << mock_turtle.GetX() << std::endl;

  return EXIT_SUCCESS;
}

// -- eof
