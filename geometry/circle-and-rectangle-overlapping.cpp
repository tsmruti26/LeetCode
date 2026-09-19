class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        // Find closest point on rectangle to circle center
        int xClosest = std::max(x1, std::min(xCenter, x2));
        int yClosest = std::max(y1, std::min(yCenter, y2));

        // Compute squared distance from circle center to that point
        long long dx = xCenter - xClosest;
        long long dy = yCenter - yClosest;
        long long distSq = dx * dx + dy * dy;
        long long radiusSq = 1LL * radius * radius;

        return distSq <= radiusSq;
    }
};