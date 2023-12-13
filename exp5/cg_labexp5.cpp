#include <iostream>
#include <graphics.h>
using namespace std;

void drawKochCurve(int it, int x1, int y1, int x5, int y5)
{
    if (it == 0)
    {
        line(x1, y1, x5, y5); // Base case: Draw a line
    }
    else
    {
        int x2 = x1 + (x5 - x1) / 3;
        int y2 = y1 + (y5 - y1) / 3;

        int x3 = x1 + 2 * (x5 - x1) / 3;
        int y3 = y1 + 2 * (y5 - y1) / 3;

        int x4 = (x2 + x3) / 2 - (y3 - y2) * sqrt(3) / 2;
        int y4 = (y2 + y3) / 2 + (x3 - x2) * sqrt(3) / 2;

        drawKochCurve(it - 1, x1, y1, x2, y2);
        drawKochCurve(it - 1, x2, y2, x4, y4);
        drawKochCurve(it - 1, x4, y4, x3, y3);
        drawKochCurve(it - 1, x3, y3, x5, y5);
    }
}

int main()
{
    int it;
    cout << "Enter Number Of Iterations: ";
    cin >> it;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawKochCurve(it, 100, 300, 500, 300);

    delay(5000);
    closegraph();
    return 0;
}
