// C++ code for rotating pyramid
#include <GL/glut.h>
#include <math.h>
using namespace std;

float rotationAngle = 0.0f;

void init() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Reset the model-view matrix

    glTranslatef(0.0f, 0.0f, -7.0f); // Move the pyramid into the scene
    glRotatef(rotationAngle, 1.0f, 1.0f, 0.0f); // Apply rotation on the X and Y axes

    // Draw pyramid with 4 triangular faces
    glBegin(GL_TRIANGLES);

    // Front face (Red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right face (Green)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back face (Blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left face (Yellow)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glutSwapBuffers(); // Swap the front and back buffers
}

void update(int value) {
    rotationAngle += 1.0f; // Increase the rotation angle
    if (rotationAngle > 360) {
        rotationAngle -= 360;
    }
    glutPostRedisplay(); // Request display update
    glutTimerFunc(16, update, 0); // 60 FPS (~16 ms per frame)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating 3D Pyramid");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // 25 ms timer
    glutMainLoop();

    return 0;
}