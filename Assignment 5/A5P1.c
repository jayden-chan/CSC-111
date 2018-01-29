/*
* Name: Jayden Chan
* Date: 2017/11/02
* Assignment: A5P1
* Description: Creates "modern" art.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILENAME ("MyCSC111Art.html")
#define ERR ("Error creating")
#define BACKGROUNDCOL ("white")
#define FRAMECOL ("blue")
#define FRAMEWIDTH (10)
#define CANVASWIDTH (800)
#define CANVASHEIGHT (300)
#define PXMIN (0)
#define PXMAX (800)
#define PYMIN (0)
#define PYMAX (300)
#define RADMIN (20)
#define RADMAX (170)
#define CRMIN (0)
#define CRMAX (255)
#define CGMIN (0)
#define CGMAX (255)
#define CBMIN (0)
#define CBDMAX (255)
#define OPMIN (0.0)
#define OPMAX (1.0)

int randInt(int, int);
double randFloat(double, double);
void genIntsFloats(int, int, int, double, double);
FILE* createFile(char*);
void writePrologue(FILE*);
void writeEpilogue(FILE*);
void genCSC111Art(FILE*);
void circle(FILE*, int, int, int, int, int, int, double);
void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int cr, int cg, int cb, double op);
void square(FILE* ofp, int cx, int cy, int rx, int cr, int cg, int cb, double op);
void rectangle(FILE* ofp, int cx, int cy, int rx, int ry, int cr, int cg, int cb, double op);

int main(void) {
    time_t t;
    srand((unsigned)time(&t)); // init random number generator

    FILE* ofp = createFile(FILENAME);
    printf("File %s open\n", FILENAME);

    writePrologue(ofp);
    printf("Prologue written into %s\n", FILENAME);
    genCSC111Art(ofp);
    printf("CSC111 Art written into of %s\n", FILENAME);
    writeEpilogue(ofp);
    printf("Epilogue written into %s\n", FILENAME);

    fclose(ofp);
    printf("File %s closed\n", FILENAME);
    return EXIT_SUCCESS;
}/*main*/

void genCSC111Art(FILE* ofp) {
    
    for(int i = 1; i <= 10; i++) {
        int cx = randInt(PXMIN, PXMAX);
        int cy = randInt(PYMIN, PYMAX);
        int rad = randInt(RADMIN, RADMAX);
        int ry = randInt(RADMIN, RADMAX);
        int cr = randInt(CRMIN, CRMAX);
        int cg = randInt(CGMIN, CGMAX);
        int cb = randInt(CBMIN, CBDMAX);
        double op = randFloat(OPMIN, OPMAX);

        switch(randInt(0, 3)) {
            case 0:
                circle(ofp, cx, cy, rad, cr, cg, cb, op);
                printf("%2d Cir: (x,y,r)           (r,g,b)       op\n", i);
                printf("%2d Cir: (%3d,%3d,%3d)     (%3d,%3d,%3d) %.2f\n", i, cx, cy, rad, cr, cg, cb, op);
                break;
            case 1:
                ellipse(ofp, cx, cy, rad, ry, cr, cg, cb, op);
                printf("%2d Ell: (x,y|rx,ry)       (r,g,b)       op\n", i);
                printf("%2d Ell: (%3d,%3d|%3d,%3d) (%3d,%3d,%3d) %.2f\n", i, cx, cy, rad, ry, cr, cg, cb, op);
                break;
            case 2:
                square(ofp, cx, cy, rad, cr, cg, cb, op);
                printf("%2d Squ: (x,y,s)           (r,g,b)       op\n", i);
                printf("%2d Squ: (%3d,%3d,%3d)     (%3d,%3d,%3d) %.2f\n", i, cx, cy, rad, cr, cg, cb, op);
                break;
            case 3:
                rectangle(ofp, cx, cy, rad, ry, cr, cg, cb, op);
                printf("%2d Rec: (x,y|w,h)         (r,g,b)       op\n", i);
                printf("%2d Rec: (%3d,%3d|%3d,%3d) (%3d,%3d,%3d) %.2f\n", i, cx, cy, rad, ry, cr, cg, cb, op);
                break;
            default:
                break;
        }
    }

    for(int i = 1; i <= 990; i++) {
        int cx = randInt(PXMIN, PXMAX);
        int cy = randInt(PYMIN, PYMAX);
        int rad = randInt(RADMIN, RADMAX);
        int ry = randInt(RADMIN, RADMAX);
        int cr = randInt(CRMIN, CRMAX);
        int cg = randInt(CGMIN, CGMAX);
        int cb = randInt(CBMIN, CBDMAX);
        double op = randFloat(OPMIN, OPMAX);

        switch(randInt(0, 3)) {
            case 0:
                circle(ofp, cx, cy, rad, cr, cg, cb, op);
                break;
            case 1:
                ellipse(ofp, cx, cy, rad, ry, cr, cg, cb, op);
                break;
            case 2:
                square(ofp, cx, cy, rad, cr, cg, cb, op);
                break;
            case 3:
                rectangle(ofp, cx, cy, rad, ry, cr, cg, cb, op);
                break;
            default:
                break;
        }
    }


}/*genCSC111Art*/

void circle(FILE* ofp, int cx, int cy, int rad, int cr, int cg, int cb, double op){
    fprintf(ofp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\"", cx, cy, rad);
    fprintf(ofp, " style=\"fill:rgb(%d,%d,%d);", cr, cg, cb);
    fprintf(ofp, " fill-opacity:%.2f\"></circle>\n", op);
}/*circle*/

void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int cr, int cg, int cb, double op){
    fprintf(ofp, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\"", cx, cy, rx, ry);
    fprintf(ofp, " style=\"fill:rgb(%d,%d,%d);", cr, cg, cb);
    fprintf(ofp, " fill-opacity:%.2f\"></ellipse>\n", op);
}/*ellipse*/

void square(FILE* ofp, int cx, int cy, int rx, int cr, int cg, int cb, double op){
    fprintf(ofp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"", cx, cy, rx, rx);
    fprintf(ofp, " style=\"fill:rgb(%d,%d,%d);", cr, cg, cb);
    fprintf(ofp, " fill-opacity:%.2f\"></rect>\n", op);
}/*square*/

void rectangle(FILE* ofp, int cx, int cy, int rx, int ry, int cr, int cg, int cb, double op){
    fprintf(ofp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"", cx, cy, rx, ry);
    fprintf(ofp, " style=\"fill:rgb(%d,%d,%d);", cr, cg, cb);
    fprintf(ofp, " fill-opacity:%.2f\"></rect>\n", op);
}/*rectangle*/

int randInt(int min, int max) {
    return (rand() % (max - min + 1) + min);
}/*randInt*/

double randFloat(double min, double max){
    double r = (double)rand() / (double)RAND_MAX;
    return ((max-min) * r + min);
}/*randFloat*/

void genIntsFloats(int rands, int imin, int imax, double fmin, double fmax){
    printf("RandInts: ");
    for (int k=0; k<rands; k++) printf("%d ", randInt(imin, imax));
    printf("\n");
    printf("RandFloats: ");
    for (int k=0; k<rands; k++) printf("%.2f ", randFloat(fmin, fmax));
    printf("\n");
}/*genIntsFloats*/

FILE* createFile(char* fnam) {
    FILE* ofp = fopen(fnam, "w");
    if (ofp == NULL) {
        printf("%s %s\n", ERR, fnam);
        exit(EXIT_FAILURE);
    }/*if*/
    return ofp;
}/*createFile*/

void writePrologue(FILE* ofp) {
    fprintf(ofp, "<!DOCTYPE html>\n");
    fprintf(ofp, "<html>\n");
    fprintf(ofp, "<head>\n");
    fprintf(ofp, "<title>My CSC 111 Art</title>\n");
    fprintf(ofp, "</head>\n");
    fprintf(ofp, "<body>\n");
    fprintf(ofp, "<svg width=\"%d\" height=\"%d\">\n", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" ", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\"></rect>\n", BACKGROUNDCOL, FRAMECOL,FRAMEWIDTH);
}/*writePrologue*/

void writeEpilogue(FILE* ofp) {
    fprintf(ofp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" ", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "fill=\"none\" stroke=\"%s\" stroke-width=\"%d\"></rect>\n", FRAMECOL,FRAMEWIDTH);
    fputs("</svg>\n", ofp);
    fputs("</body>\n", ofp);
    fputs("</html>\n", ofp);
}/*writeEpilogue*/
