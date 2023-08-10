#include <cmath>
#include <iostream>
#include <iostream>
#define LENGTH 10
#define A 2
#define B 3
#define C 4
#define OUT_OF_RANGE_ANGLE_LOW -45
#define OUT_OF_RANGE_ANGLE_HIGH 90
int calculateMotorAngles(float position_data[3], float fi_array[3]) {
float x = position_data[0];
float y = position_data[1];
float z = position_data[2];
float Ei[3] = {2 * LENGTH * (y + A), -LENGTH * (sqrt(3) * (x + B) + y + C),
LENGTH * (sqrt(3) * (x - B) - y - C)};
float Fi[3] = {2 * z * LENGTH, 2 * z * LENGTH, 2 * z * LENGTH};
float Gi[3] = {std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) +
std::pow(A, 2) + std::pow(LENGTH, 2) + 2 * y * A - std::pow(LENGTH, 2),
std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(B,
2) + std::pow(C, 2) + std::pow(LENGTH, 2) + 2 * x * B + 2
* y * C - std::pow(LENGTH, 2),
std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(B,
2) + std::pow(C, 2) + std::pow(LENGTH, 2) - 2 * x * B + 2
* y * C - std::pow(LENGTH, 2)};
for (int i = 0; i < 3; i++) {
float temp = 2 * std::atan((-Fi[i] + std::sqrt(std::pow(Fi[i], 2) +
std::pow(Ei[i], 2) - std::pow(Gi[i], 2))) / (Gi[i] - Ei[i]));
if (temp >= OUT_OF_RANGE_ANGLE_LOW && temp <= OUT_OF_RANGE_ANGLE_HIGH) {
fi_array[i] = temp * 180 / 3.14;
} else {
float temp = 2 * std::atan((-Fi[i] - std::sqrt(std::pow(Fi[i], 2) +
std::pow(Ei[i], 2) - std::pow(Gi[i], 2))) / (Gi[i] - Ei[i]));
if (temp >= OUT_OF_RANGE_ANGLE_LOW && temp <=
OUT_OF_RANGE_ANGLE_HIGH) {
fi_array[i] = temp * 180 / 3.14;
} else {
fi_array[0] = -100;
fi_array[1] = -100;
fi_array[2] = -100;
return 0; // -1 is error - coordinates out of range
}
}
}
return 1;
}

int main()
{
float position_data[3] = {1.0, 2.0, 3.0};
float fi_array[3];
int result = calculateMotorAngles(position_data, fi_array);
if(result == 1){
std::cout << "Inverse kinematics calculation successful" << std::endl;
std::cout << "Motor angles: " << fi_array[0] << ", " << fi_array[1] <<
", " << fi_array[2] << std::endl;
}
else{
std::cout << "Inverse kinematics calculation failed" << std::endl;
}
return 0;
}
