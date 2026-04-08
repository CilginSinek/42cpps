#include "Point.hpp"

int main(void)
{

    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // === Basic Tests ===
    Point point1(5, 5);
    Point point2(15, 5);
    Point point3(-5, -5);

    bool isInside1 = bsp(a, b, c, point1);
    bool isInside2 = bsp(a, b, c, point2);
    bool isInside3 = bsp(a, b, c, point3);

    // === Edge Case: Points on Vertices ===
    Point onVertexA(0, 0);
    Point onVertexB(10, 0);
    Point onVertexC(0, 10);

    bool onVertARes = bsp(a, b, c, onVertexA);
    bool onVertBRes = bsp(a, b, c, onVertexB);
    bool onVertCRes = bsp(a, b, c, onVertexC);

    // === Edge Case: Points on Edges ===
    Point onEdgeAB(5, 0); // On AB
    Point onEdgeBC(5, 5); // On BC
    Point onEdgeCA(0, 5); // On CA

    bool onEdgeABRes = bsp(a, b, c, onEdgeAB);
    bool onEdgeBCRes = bsp(a, b, c, onEdgeBC);
    bool onEdgeCARes = bsp(a, b, c, onEdgeCA);

    // === Edge Case: Centroid ===
    Point centroid(10.0f / 3.0f, 10.0f / 3.0f);
    bool centroidRes = bsp(a, b, c, centroid);

    // === Edge Case: Very Close to Edge (on edge) ===
    Point nearEdge(4.9f, 5.1f);
    bool nearEdgeRes = bsp(a, b, c, nearEdge);

    // === Print Results ===
    std::cout << "\n=== Basic Tests ===" << std::endl;
    std::cout << "Res: Point 1 (5, 5) is " << (isInside1 ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point 2 (15, 5) is " << (isInside2 ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point 3 (-5, -5) is " << (isInside3 ? "inside" : "outside") << " the triangle." << std::endl;

    std::cout << "\n=== Edge Case: Points on Vertices ===" << std::endl;
    std::cout << "Res: Point on vertex A (0, 0) is " << (onVertARes ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point on vertex B (10, 0) is " << (onVertBRes ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point on vertex C (0, 10) is " << (onVertCRes ? "inside" : "outside") << " the triangle." << std::endl;

    std::cout << "\n=== Edge Case: Points on Edges ===" << std::endl;
    std::cout << "Res: Point on edge AB (5, 0) is " << (onEdgeABRes ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point on edge BC (5, 5) is " << (onEdgeBCRes ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "Res: Point on edge CA (0, 5) is " << (onEdgeCARes ? "inside" : "outside") << " the triangle." << std::endl;

    std::cout << "\n=== Edge Case: Centroid ===" << std::endl;
    std::cout << "Res: Point at centroid (3.33, 3.33) is " << (centroidRes ? "inside" : "outside") << " the triangle." << std::endl;

    std::cout << "\n=== Edge Case: Very Close to Edge ===" << std::endl;
    std::cout << "Res: Point near edge (4.9, 5.1) is " << (nearEdgeRes ? "inside" : "outside") << " the triangle." << std::endl;
}
