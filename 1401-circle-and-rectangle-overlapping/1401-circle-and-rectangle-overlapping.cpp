class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi, yi; //nearest point to the circle's center
        
        //nearest xi
        if(x1>xCenter) xi=x1;
        else if(x2<xCenter) xi=x2;
        else xi=xCenter;

        //nearest yi
        if(y1>yCenter) yi=y1;
        else if(y2<yCenter) yi=y2;
        else yi=yCenter;

        //distance btw (xi,yi) and (xCenter,yCenter)
        int dist=sqrt(pow((xi-xCenter),2) + pow((yi-yCenter),2));

        //if distance > radius => non-overlapping, else => overlapping
        if(dist>radius) return false;
        return true;
    }
};