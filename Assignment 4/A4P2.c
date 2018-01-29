/*
 * Name: Jayden Chan
 * Assignment: A4 Part 2
 * Date: Oct 24 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME ("MyPumpkin.html")
#define CANVASWIDTH (1100)
#define CANVASHEIGHT (350)
#define PXOFFSET (800)
#define PYOFFSET (20)
#define PUMPKIN_COLOUR (255)

FILE* createFile(char*);
void writePrologue(FILE* fo);
void writePumpkin(FILE* fo, int, int, int, float);
void writeEpilogue(FILE* fo);

int main(void){

    float sf_rand;

    FILE* f = createFile(FILENAME);
    writePrologue(f);
    for(int i = 0; i < 20; i++) {
        sf_rand = (float)rand() / (float)(RAND_MAX/1.0);
        int x = rand() % PXOFFSET;
        int y = rand() % (PYOFFSET + 120);
        int col = rand() % PUMPKIN_COLOUR;
        writePumpkin(f, x, y, col, sf_rand);
    }
    writeEpilogue(f);
    fclose(f);
    return EXIT_SUCCESS;
}/*main*/

FILE* createFile(char* fnam) {
    FILE* fo = fopen(FILENAME, "w");
    if (fo == NULL) {
        printf("WriteFile: file error\n");
        exit(EXIT_FAILURE);
    }/*if*/
    return fo;
}/*createFile*/

void writePrologue(FILE* fo) {
    fprintf(fo, "<!DOCTYPE html>\n");
    fprintf(fo, "<html>\n");
    fprintf(fo, "<head>\n");
    fprintf(fo, "<title>My CSC 111 Web Page</title>\n");
    fprintf(fo, "</head>\n");
    fprintf(fo, "<body>\n");
    fprintf(fo, "<svg width=\"%d\" height=\"%d\">\n", CANVASWIDTH, CANVASHEIGHT);
    fprintf(fo, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" style=\"fill:rgb(0,0,0)\"></rect>\n", CANVASWIDTH, CANVASHEIGHT);
}/*writePrologue*/

void writePumpkin(FILE* fo, int px, int py, int col, float sf) {
    fprintf(fo, "<g transform=\"translate(%d,%d) scale(%.1f)\">\n", px, py, sf);
    fprintf(fo, "<circle cx=\"150\" cy=\"150\" r=\"100\" style=\"fill:rgb(%d,118,25)\"></circle>\n", col);
    fprintf(fo, "<circle cx=\"210\" cy=\"153\" r=\"102\" style=\"fill:rgb(%d,118,25)\"></circle>\n", col);
    fprintf(fo, "<rect x=\"160\" y=\"-50\" height=\"60\" width=\"20\" rx=\"20\" ry=\"20\" style=\"fill:rgb(25,%d,50)\" transform=\"rotate(30 50 50)\"></rect>\n", col);
    fprintf(fo, "<text x=\"120\" y=\"230\" >Happy Halloween!</text>\n", fo);
    fprintf(fo, "</g>\n");
}/*writePumpkin*/

void writeEpilogue(FILE* fo) {
    fputs("</svg>\n", fo);
    fputs("</body>\n", fo);
    fputs("<html>\n", fo);
}/*writeEpilogue*/
