//#include <irrKlang.h>
//using namespace irrklang;

#include<windows.h>
#include <GL/glut.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Global variables
struct Entity {
    float x, y;
    bool active;
};


vector<Entity> insects;
vector<Entity> insects2;
Entity timonProjectile = { 0.0, 0.0, false };
Entity bombaProjectile = { 0.0, 0.0, false };
float timonX = 200.0, bombaX = 600.0;
int timonScore = 0, bombaScore = 0;

// Game state
bool gameOver = false;

// Function to render text
void renderText(float x, float y, const string& text) {
    glRasterPos2f(x, y);
    for (char c : text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

// Initialize the game
void init() {
    glClearColor(1.6, 0.9, 0.2, 1.0); // savana forest background


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 600);
    srand(static_cast<unsigned int>(time(0))); ///every run is deff
}
void drawbackground() {
    glColor3f(0.0, 0.6, 0.8); //b
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 600.0f, 0.0f); //top left
    glVertex3f(800.0f, 600.0f, 0.0f); //top right
    glVertex3f(800.0f, 300.0f, 0.0f); //botom right
    glVertex3f(0.0f, 300.0f, 0.0f);  //botom left
    glEnd();
    glColor3f(0.0, 0.0, 0.0); //b tree
    glBegin(GL_POLYGON);
    glVertex3f(55.0f, 400.0f, 0.0f);  //top l
    glVertex3f(60.0f, 400.0f, 0.0f);  //top r
    glVertex3f(75.0f, 270.0f, 0.0f); //botom l
    glVertex3f(60.0f, 270.0f, 0.0f); //botom r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(60.0f, 345.0f, 0.0f);  //mid r 1
    glVertex3f(110.0f, 355.0f, 0.0f);  //mid r 2
    glVertex3f(60.0f, 340.0f, 0.0f);  //mid r 3
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(60.0f, 360.0f, 0.0f);  //mid l 1
    glVertex3f(-60.0f, 385.0f, 0.0f);  //mid l 2
    glVertex3f(60.0f, 355.0f, 0.0f);  //mid l 3
    glEnd();
}
// Draw Timon and Bomba
void drawPlayers() {
    // Timon
    glColor3f(0.8, 0.6, 0.4); // baige
    //body
    glBegin(GL_POLYGON);
    glVertex3f(timonX - 20.0f, 70.0f, 0.0f); //top right
    glVertex3f(timonX + 20.0f, 70.0f, 0.0f); //top left
    glVertex3f(timonX + 30.0f, 0.0f, 0.0f); //botom right
    glVertex3f(timonX - 30.0f, 0.0f, 0.0f);  //botom left
    glEnd();
    //head
    glBegin(GL_POLYGON);
    glVertex3f(timonX - 25.0f, 106.0f, 0.0f);    // Top-left
    glVertex3f(timonX + 0.0f, 110.0f, 0.0f);    // Top
    glVertex3f(timonX + 25.0f, 106.0f, 0.0f);    // Top-right
    glVertex3f(timonX + 25.0f, 75.0f, 0.0f);    // Bottom-right
    glVertex3f(timonX + 0.0f, 50.0f, 0.0f);    // Bottom
    glVertex3f(timonX - 25.0f, 75.0f, 0.0f);    // Bottom-left
    glEnd();
    //hair
    glColor3f(0.8, 0.1, 0.1); // red
    glBegin(GL_POLYGON);
    glVertex3f(timonX - 25.0f, 106.0f, 0.0f); //top left
    glVertex3f(timonX - 20.0f, 110.0f, 0.0f); //top left2
    glVertex3f(timonX - 20.0f, 100.0f, 0.0f);    // Bottom.5
    glVertex3f(timonX + 0.0f, 110.0f, 0.0f);   // Top
    glVertex3f(timonX + 25.0f, 106.0f, 0.0f); //top right
    glVertex3f(timonX + 20.0f, 100.0f, 0.0f);    // Bottom.5
    glVertex3f(timonX + 20.0f, 110.0f, 0.0f); //top right 2
    glVertex3f(timonX + 0.0f, 100.0f, 0.0f);    // Bottom
    glEnd();
    //ears
    glColor3f(0.1, 0.1, 0.1); // black
    glBegin(GL_POLYGON);
    glVertex3f(timonX - 25.0f, 100.0f, 0.0f); //top left
    glVertex3f(timonX - 35.0f, 85.0f, 0.0f);   // mid
    glVertex3f(timonX - 25.0f, 80.0f, 0.0f);    // Bottom-left
    glEnd();
    //ears 2
    glBegin(GL_POLYGON);
    glVertex3f(timonX + 25.0f, 100.0f, 0.0f); //top left
    glVertex3f(timonX + 35.0f, 85.0f, 0.0f);   // mid
    glVertex3f(timonX + 25.0f, 80.0f, 0.0f);    // Bottom-left
    glEnd();
    glColor3f(0.7, 0.5, 0.3); // dark baige
    glBegin(GL_POLYGON);
    glVertex3f(timonX - 20.0f, 70.0f, 0.0f); //top right
    glVertex3f(timonX + 20.0f, 70.0f, 0.0f); //top left
    glVertex3f(timonX + 30.0f, 0.0f, 0.0f); //botom right
    glVertex3f(timonX - 30.0f, 0.0f, 0.0f);  //botom left
    glEnd();
    //////////////////////////////////////////////////////////////////////////////
        // Bomba
    glColor3f(0.5, 0.2, 0.02); // brown
    glBegin(GL_POLYGON);
    glVertex3f(bombaX - 25.0f, 150.0f, 0.0f); // Top-left
    glVertex3f(bombaX + 25.0f, 150.0f, 0.0f); // Top-right
    glVertex3f(bombaX + 40.0f, 100.0f, 0.0f); // * mid-right 1
    glVertex3f(bombaX + 50.0f, 90.0f, 0.0f); // * mid-right 2
    glVertex3f(bombaX + 50.0f, 0.0f, 0.0f); // Bottom-right
    glVertex3f(bombaX - 50.0f, 0.0f, 0.0f); // Bottom-left
    glVertex3f(bombaX - 50.0f, 90.0f, 0.0f); // mid-left 2
    glVertex3f(bombaX - 40.0f, 100.0f, 0.0f); // mid-left 1
    glEnd();
    //horns
    glColor3f(0.75, 0.75, 0.75); //dark brown
    glBegin(GL_POLYGON); //L horn
    glVertex3f(bombaX - 25.0f, 150.0f, 0.0f); // Top-left
    glVertex3f(bombaX - 50.0f, 170.0f, 0.0f); // mid-left
    glVertex3f(bombaX - 36.5f, 120.0f, 0.0f); // bot-left
    glEnd();
    //right horn
    glBegin(GL_POLYGON);
    glVertex3f(bombaX + 24.4f, 150.0f, 0.0f); // Top-left
    glVertex3f(bombaX + 50.0f, 170.0f, 0.0f); // mid-left
    glVertex3f(bombaX + 35.0f, 120.0f, 0.0f); // bot-left
    glEnd();
    //back hair
    glColor3f(0.2, 0.05, 0.01); //dark brown
    glBegin(GL_POLYGON);
    glVertex3f(bombaX - 20.0f, 150.0f, 0.0f); // Top-left
    glVertex3f(bombaX + 20.0f, 150.0f, 0.0f); // Top-right
    glVertex3f(bombaX + 0.0f, 50.0f, 0.0f); // bottom
    glEnd();
}

// Draw projectiles
void drawProjectiles() {
    if (timonProjectile.active) {
        glColor3f(1.0, 0.0, 0.0); // Red projectil
        glRectf(timonProjectile.x - 5, timonProjectile.y, timonProjectile.x + 5, timonProjectile.y + 10);
    }
    if (bombaProjectile.active) {
        glColor3f(0.0, 0.0, 1.0); // Blue projectil
        glRectf(bombaProjectile.x - 5, bombaProjectile.y + 40, bombaProjectile.x + 5, bombaProjectile.y + 55);
    }
}

// Draw insects
void drawInsects() {
    for (auto& insect : insects) { 
        if (insect.active) {
            glColor3f(0.0, 0.0, 0.0); //  insects 1 b
            glBegin(GL_POLYGON);
            glVertex3f(insect.x - 2.5f, insect.y + 1.6f, 0.0f);    // Top-left
            glVertex3f(insect.x + 0.0f, insect.y + 1.10f, 0.0f);    // Top
            glVertex3f(insect.x + 2.5f, insect.y + 1.6f, 0.0f);    // Top-right
            glVertex3f(insect.x + 2.5f, insect.y - 7.5f, 0.0f);    // Bottom-right
            glVertex3f(insect.x + 0.0f, insect.y - 5.0f, 0.0f);    // Bottom
            glVertex3f(insect.x - 2.5f, insect.y - 7.5f, 0.0f);    // Bottom-left
            glEnd();

            glBegin(GL_POLYGON);
            glVertex3f(insect.x - 10.0f, insect.y + 0.0f, 0.0f); //top left
            glVertex3f(insect.x, insect.y, 0.0f); //mid
            glVertex3f(insect.x - 5.0f, insect.y - 15.0f, 0.0f); //botom l
            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(insect.x + 10.0f, insect.y + 0.0f, 0.0f); //top r
            glVertex3f(insect.x, insect.y, 0.0f); //mid
            glVertex3f(insect.x + 5.0f, insect.y - 15.0f, 0.0f); //botom right

            glEnd();

        }
    }
}
// Draw insects2
void drawInsects2() {
    for (auto& insect2 : insects2) {
        if (insect2.active) {
            //glColor3f(1.0, 1.0, 1.0); //  insects 2 w    
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.0f); // Brown color for the body
            glVertex3f(insect2.x - 2.0f, insect2.y + 10.0f, 0.0f); // Top
            glVertex3f(insect2.x + 2.0f, insect2.y + 10.0f, 0.0f);
            glVertex3f(insect2.x + 2.0f, insect2.y - 5.0f, 0.0f); // Bottom
            glVertex3f(insect2.x - 2.0f, insect2.y - 5.0f, 0.0f);
            glEnd();
            glColor3f(0.5f, 0.3f, 0.0f); // Brown color for the body
            glBegin(GL_POLYGON);
            glVertex3f(insect2.x - 15.0f, insect2.y + 20.0f, 0.0f); //top left
            glVertex3f(insect2.x, insect2.y, 0.0f); //mid
            glVertex3f(insect2.x - 15.0f, insect2.y - 0.0f, 0.0f); //botom l
            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(insect2.x + 15.0f, insect2.y + 20.0f, 0.0f); //top r
            glVertex3f(insect2.x, insect2.y, 0.0f); //mid
            glVertex3f(insect2.x + 15.0f, insect2.y - 0.0f, 0.0f); //botom right
            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(insect2.x - 12.0f, insect2.y - 2.0f, 0.0f); //top left
            glVertex3f(insect2.x, insect2.y, 0.0f); //mid
            glVertex3f(insect2.x - 12.0f, insect2.y - 15.0f, 0.0f); //botom l
            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(insect2.x + 12.0f, insect2.y - 2.0f, 0.0f); //top r
            glVertex3f(insect2.x, insect2.y, 0.0f); //mid
            glVertex3f(insect2.x + 12.0f, insect2.y - 15.0f, 0.0f); //botom r
            glEnd();
        }
    }
}

// Update projectiles
void updateProjectiles() {
    if (timonProjectile.active) {
        timonProjectile.y += 5.0;
        if (timonProjectile.y > 600)
            timonProjectile.active = false;
    }
    if (bombaProjectile.active) {
        bombaProjectile.y += 5.0;
        if (bombaProjectile.y > 600)
            bombaProjectile.active = false;
    }
}

// Spawn insects
void spawnInsects() {
    if (rand() % 100 < 1) { // 2% chance to spawn an insect per frame
        insects.push_back({ static_cast<float>(rand() % 800), 600, true });
    }
}
void spawnInsects2() {
    if (rand() % 100 < 1) { // 1% chance to spawn an insect per frame
        insects2.push_back({ static_cast<float>(rand() % 800), static_cast<float>(600), true });
    }
}

// Update insects
void updateInsects() {
    for (auto& insect : insects) {
        if (insect.active) {
            insect.y -= 3.0; // Move down
            if (insect.y < 0) {
                insect.active = false; // Insect missed
            }
        }
    }
}
// Update insects2
void updateInsects2() {
    for (auto& insect2 : insects2) {
        if (insect2.active) {
            insect2.y -= 3.0; // Move down
            if (insect2.y < 0) {
                insect2.active = false; // Insect missed
            }
        }
    }
}
// Check collisions
void checkCollisions() {
    for (auto& insect : insects) {
        if (!insect.active)
            continue;

        if (timonProjectile.active &&
            timonProjectile.x > insect.x - 10 &&
            timonProjectile.x < insect.x + 10 &&
            timonProjectile.y > insect.y - 10 &&
            timonProjectile.y < insect.y + 10) {
            insect.active = false;
            timonProjectile.active = false;
            timonScore++;
            PlaySound(TEXT("X:\\download\\new\\mixkit-retro-game-notification-212.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        if (bombaProjectile.active &&
            bombaProjectile.x > insect.x - 10 &&
            bombaProjectile.x < insect.x + 10 &&
            bombaProjectile.y > insect.y - 10 &&
            bombaProjectile.y < insect.y + 10) {
            insect.active = false;
            bombaProjectile.active = false;
            bombaScore++;
            PlaySound(TEXT("X:\\download\\new\\mixkit-retro-game-notification-212.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
    // Check collisions with insects2
    for (auto& insect2 : insects2) {
        if (!insect2.active)
            continue;

        if (timonProjectile.active &&
            timonProjectile.x > insect2.x - 10 &&
            timonProjectile.x < insect2.x + 10 &&
            timonProjectile.y > insect2.y - 10 &&
            timonProjectile.y < insect2.y + 10) {
            insect2.active = false;
            timonProjectile.active = false;
            timonScore--; // Deduct score for hitting butterfly
            PlaySound(TEXT("X:\\download\\new\\wrong-47985.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if (bombaProjectile.active &&
            bombaProjectile.x > insect2.x - 10 &&
            bombaProjectile.x < insect2.x + 10 &&
            bombaProjectile.y > insect2.y - 10 &&
            bombaProjectile.y < insect2.y + 10) {
            insect2.active = false;
            bombaProjectile.active = false;
            bombaScore--; // Deduct score for hitting butterfly
            PlaySound(TEXT("X:\\download\\new\\wrong-47985.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
    }
}

// Render the game
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (gameOver) {
        string result;
        if (timonScore > bombaScore) {
            result = "Timon Wins!";
        }
        else {
            result = "Pumbaa Wins!";

        }
        //glColor3f(0.0, 1.0, 1.0); // Set text color
        renderText(800 / 2 - 50, 600 / 2, result);
        //PlaySound(TEXT("X:\\download\\new\\Undertale OST： 059 - Spider Dance.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP  );
        glutSwapBuffers();
        return; //needs to stay or hi7sal error
    }
    drawbackground();

    // Draw game objects
    drawPlayers();
    drawProjectiles();
    drawInsects();
    drawInsects2();
    // Display scores
    renderText(10, 600 - 30, "Timon Score: " + to_string(timonScore));
    renderText(800 - 200, 600 - 30, "Bomba Score: " + to_string(bombaScore));

    glutSwapBuffers();
}

// Handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    if (gameOver)
        return;

    switch (key) {      
    case 'a': timonX -= 10.0; break; // Move Timon left
    case 'd': timonX += 10.0; break; // Move Timon right
    case 'w': // Fire Timon's projectile
        if (!timonProjectile.active) {
            timonProjectile = { timonX, 100.0, true };
        }
        break;

    case 'j': bombaX -= 10.0; break; // Move Bomba left
    case 'l': bombaX += 10.0; break; // Move Bomba right
    case 'i': // Fire Bomba's projectile
        if (!bombaProjectile.active) {
            bombaProjectile = { bombaX, 100.0, true };
        }
        break;

    case 27: exit(0); // Exit on ESC
    }
}

// Update game state
void timer(int value) {
    if (gameOver==false) {
        updateProjectiles();
        spawnInsects();
        spawnInsects2();
        updateInsects();
        updateInsects2();
        checkCollisions();

        if (timonScore >= 2 || bombaScore >= 10) {
            gameOver = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 60 FPS
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Timon and Bomba Game");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //PlaySound(TEXT("X:\\download\\new\\Undertale OST： 059 - Spider Dance.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP  );
    init();

    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}