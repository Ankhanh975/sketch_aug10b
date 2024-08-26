#include <Servo.h> // Include the Servo library

int sign(float number)
{
    return (number > 0) ? 1 : -1;
}
class ServoMaster
{
private:
    const int numServos = 4; // Number of servos

    int servoPins[4] = {9, 12, 10, 11}; // Pins connected to the servos

    float offsetServo[4] = {4.0, -7.0, -9.0, -6.0};

    float angle[4] = {90.0, 90.0, 90.0, 90.0};

    float set_angle[4] = {90.0, 90.0, 90.0, 90.0};

    Servo servos[4]; // Create an array of Servo objects

    void attach()
    {
        for (int i = 0; i < this->numServos; i++)
        {
            this->servos[i].attach(servoPins[i]);
            int initialPosition = 90;        // Default initial position
            this->write(i, initialPosition); // Set each servo to its corrected initial position
        }
    }
    void write(int servoNum, float initialPosition)
    {
        // if (servoNum == 1 || servoNum == 3)
        // {
            // initialPosition = 180 - initialPosition;
        // }
        float _angle;
        initialPosition += offsetServo[servoNum];
        _angle = constrain(initialPosition, 0, 180); // Ensure position is within bounds
        float final_pos;
        if (servoNum == 0)
        {
            final_pos = (_angle - 90) * 0.55 + 90;
        }
        else if (servoNum == 1)
        {
            final_pos = (_angle - 90) * 0.55 + 90;
        }
        else if (servoNum == 2)
        {
            final_pos = (_angle - 90) * 0.55 + 90;
        }
        else if (servoNum == 3)
        {
            final_pos = (_angle - 90) * 0.55 + 90;
        }
        this->servos[servoNum].write(final_pos);
    }

public:
    void init()
    {
        this->attach();
    }
    void update()
    {

        for (int ii = 0; ii < 4; ii++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (set_angle[ii] != angle[ii])
                {
                    angle[ii] += sign(set_angle[ii] - angle[ii]) * 1.25;
                    write(ii, angle[ii]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    void setAngle(int servoNum, float angle)
    {

        int _angle = constrain(angle, 0, 180); // Ensure position is within bounds
        this->set_angle[servoNum] = _angle;
    }

    void setAngleImidiately(int servoNum, float angle)
    {
        this->write(servoNum, angle);
        this->angle[servoNum] = angle;
        this->set_angle[servoNum] = angle;
    }
    float get_angle(int num)
    {
        return angle[num];
    }
};

ServoMaster servoMaster;
long frameCount = 0;
void setup()
{
    servoMaster.init();
    delay(500);
    servoMaster.setAngleImidiately(0, 90);
    servoMaster.setAngleImidiately(1, 90);
    servoMaster.setAngleImidiately(2, 90);
    servoMaster.setAngleImidiately(3, 90);

    delay(8);

    servoMaster.setAngle(0, 120);
    servoMaster.setAngle(1, 60);
    servoMaster.setAngle(2, 60);
    servoMaster.setAngle(3, 120);

    for (int i; i < 15; i++)
    {
        delay(8);
        servoMaster.update();
    }
}
void loop()
{
    delay(1);
    delayMicroseconds(750 );
    frameCount += 1;
    servoMaster.update();
    int state = (frameCount % 170);
    if (state == 0)
    {
        servoMaster.setAngle(0, 100);
        servoMaster.setAngle(3, 100);
    }
    if (state == 20)
    {
        servoMaster.setAngle(2, 125);
    }
    if (state == 30)
    {
        servoMaster.setAngle(0, 80);
        servoMaster.setAngle(3, 80);
    }
    if (state == 50)
    {
        servoMaster.setAngle(1, 125);
    }
    if (state == 60)
    {
        servoMaster.setAngle(0, 55);
        servoMaster.setAngle(3, 55);
    }
    if (state == 80)
    {
        servoMaster.setAngle(1, 100);
        servoMaster.setAngle(2, 100);
    }
    if (state == 100)
    {
        servoMaster.setAngle(3, 125);
    }
    if (state == 110)
    {
        servoMaster.setAngle(1, 80);
        servoMaster.setAngle(2, 80);
    }
    if (state == 130)
    {
        servoMaster.setAngle(0, 120);
    }
    if (state == 150)
    {
        servoMaster.setAngle(1, 55);
        servoMaster.setAngle(2, 55);
    }
}
