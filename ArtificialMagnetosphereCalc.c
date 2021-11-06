/
#include <stdio.h>
#include <math.h>
int main()
{
   float D;
   float rx;
   float Cx;
   float WireDistance = 0;
    //printf("radius of small circle: %f m\n", rx);
    //printf("Circumference of small circle: %f m", Cx);
    
    for(int i = 1; i < 6; i++) {
        D =  D + 613818;
        rx = 3376000*cos(asin(D/3376000));
        Cx = 2*3.145*rx;
        WireDistance = WireDistance + Cx;
    }
    WireDistance = 2*WireDistance;
    
    double Pcopper = 1.68*pow(10,-8);
    double current = 3.4928*pow(10,7);
    double voltage = 5000;
    
    
    double WireArea = (Pcopper*WireDistance)/(voltage/current);
    double CrossSectionRadius = sqrt(WireArea/3.145);
    double WireVolume = WireArea*WireDistance;
    double WireMass = 8960 * WireVolume; // copper density is 8960 kg/m^3
    printf("needed surface area of wire: %f m^2\n",WireArea);
    printf("radius of wire cross section: %f m\n",CrossSectionRadius);
    printf("total wire mass: %f *10^16 kg\n",WireMass/ pow(10,16));
    printf("Wire Length on mars: %f m", WireDistance);
    return 0;
}
