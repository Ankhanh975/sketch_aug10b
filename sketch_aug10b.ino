#include <Servo.h> // Include the Servo library

int sign(float number)
{
    return (number > 0) ? 1 : -1;
}
class ServoMaster
{
private:
    const int numServos = 4; // Number of servos

    int servoPins[] = {12, 9, 11, 10}; // Pins connected to the servos

    int offsetServo[] = {-5, -7, 20, 0};

    int angle[] = {90, 90, 90, 90};

    int set_angle[] = {90, 90, 90, 90};

    Servo servos[numServos]; // Create an array of Servo objects

    void attach()
    {
        for (int i = 0; i < this->numServos; i++)
        {
            this->servos[i].attach(servoPins[i]);
            int initialPosition = 90;        // Default initial position
            this->write(i, initialPosition); // Set each servo to its corrected initial position
        }
    }
    void write(int servoNum, int initialPosition)
    {
        if (servoNum == 1 || servoNum == 3)
        {
            initialPosition = 180 - initialPosition;
        }
        int _angle;
        initialPosition += offsetServo[servoNum];
        _angle = constrain(initialPosition, 0, 180); // Ensure position is within bounds
        float final_pos;
        if (servoNum == 0)
        {
            final_pos = (_angle - 90) * 1.65 + 90;
        }
        else if (servoNum == 1)
        {
            final_pos = (_angle - 90) * 1.60 + 90;
        }
        else if (servoNum == 2)
        {
            final_pos = (_angle - 90) * 1.60 + 90;
        }
        else if (servoNum == 3)
        {
            final_pos = (_angle - 90) * 1.65 + 90;
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

        for (int ii = 0; i < 4; i++)
        {
            for (int i = 0; i < 2; i++)
            {
                if (set_angle[ii] != angle[ii])
                {
                    angle[ii] += sign(set_angle[ii] - angle[ii]);
                    write(ii, angle[ii]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    void setAngle(int servoNum, int angle)
    {

        int _angle = constrain(angle, 0, 180); // Ensure position is within bounds
        this->set_angle[servoNum] = _angle;
    }

    void setAngleImidiately(int servoNum, int angle)
    {
        this->write(servoNum, angle);
        this->angle[servoNum] = angle;
        this->set_angle[servoNum] = angle;
    }
    int get_angle(int num)
    {
        return angle[num];
    }
};

ServoMaster servoMaster;
long frameCount = 0;
void setup()
{
    servoMaster.init();
    servoMaster.setAngle(0, 120);
    servoMaster.setAngle(1, 60);
    servoMaster.setAngle(2, 60);
    servoMaster.setAngle(3, 120);
    for (int i; i < 10; i++)
    {
        delay(5);
        servoMaster.update();
    }
}
void loop()
{
    delay(6);
    frameCount++;
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
