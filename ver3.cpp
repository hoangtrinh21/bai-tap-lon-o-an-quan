/*  Ô ĂN Quan
    người chơi B đi trước 
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <ctime>                // Hàm time
#include <cstdlib>    

using std::string;
using std::cout;
using std::endl;

struct Cell {
    int value;
    int row;
    int col; // vi tri hang, cot cua o
};
enum Directions { left, right };
SDL_Window* window = NULL;
SDL_Surface* back = NULL;
SDL_Surface* screen = NULL;
SDL_Event e;
string file;
Directions dir;
int state = 0;
int loca;
int kiem;

Cell cell[12];
Cell scoresA { 0, 235, 200 }, scoresB { 0, 285, 200 };

void initCell(Cell *x);

void quit_();

bool init();

 //chen hinh gia tri cua o vao bang
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);

 //chen hinh gia tri cua o vao bang
void loadBackground(const string file);

 //load anh de chen vao bang tai vi tri cot x hang y
void loadImage(string path, int x, int y);

void print(Cell x);
//chen anh vao bang
void initImage(Cell x);
// ve bang
void drawBoad();

void chuyenTrai(int &u, int &oChuyen);

void chuyenPhai(int &v, int &oChuyen);

void diChuyenA(int &i, int &ochuyen, int& state);

void diChuyenB(int &i, int &ochuyen, int& state);

void nhap();

void luotA(int &);

void luotB(int &);

void tinhDiemPhai(int i, int &x);

void tinhDiemTrai(int i, int &x);

Directions chuyenHuong();

bool ketThuc();

void ketQua(Cell, Cell, Cell *) ;

void daiQuanA();

void daiQuanB();

void game(int & );

void luatChoi();

int main(int argc, char* argv[]){
    srand(time(0)); // Khởi tạo seed cho hàm rand
    initCell(cell);
    if( !init() )
        return 0;
    luatChoi();
    bool quit = false;
    while( !quit ){
        while ( SDL_PollEvent ( &e ) != 0 ){
            if( e.type == SDL_QUIT )
                quit = true;
                break;
        }
        if( e.type == SDL_KEYDOWN){
            loadBackground("bkground.png");
            drawBoad();
        }
        game(state);
    }

    
    quit_();
    return 0;
}

void luatChoi(){
    loadBackground("luatchoi.png");
    return;
}

void initCell(Cell *x){
    for(int i=0; i<=6; i++){
        x[i].col = 100*i;
        if(i == 0 || i == 6){
            x[i].row = 50;
            x[i].value = 10;
        } else {
            x[i].row = 0;
            x[i].value = 5;
        }
    }
    for(int i = 7 ; i<12; i++){
        x[i].value = 5;
        x[i].row = 100;
        x[i].col = 100*(-i+12);
    }
}

void quit_(){
    SDL_FreeSurface(back);
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool init(){
    
    if( SDL_Init ( SDL_INIT_VIDEO ) == -1 ){
        SDL_GetError();
        return false;
    }
    if( IMG_Init ( IMG_INIT_PNG ) < 0 ){
        IMG_GetError();
        return 0;
    }
    window = SDL_CreateWindow("Ô ĂN QUAN", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 700, 400, SDL_WINDOW_SHOWN);
    if( window == NULL ){
        SDL_GetError();
        return false;
    }
    screen = SDL_GetWindowSurface( window );
    return true;
}
 
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

void loadBackground(const string file){  
    back = IMG_Load(file.c_str());
    if( back == NULL ){
        SDL_GetError();
    }
    SDL_BlitSurface(back, NULL, screen, NULL);
    SDL_UpdateWindowSurface( window );
}

void loadImage(string path, int x, int y){
    SDL_Surface* image = IMG_Load(path.c_str());
    ApplySurface(image, screen, x, y);
    SDL_FreeSurface(image);
}

void initImage(Cell x){ 
    switch ( x.value ){
        case 0:
            file = "img/0.png";
            break;
        case 1:
            file = "img/1.png";
            break;
        case 2:
            file = "img/2.png";
            break;
        case 3:
            file = "img/3.png";
            break;
        case 4:
            file = "img/4.png";
            break;
        case 5:
            file = "img/5.png";
            break;
        case 6:
            file = "img/6.png";
            break;
        case 7:
            file = "img/7.png";
            break;
        case 8:
            file = "img/8.png";
            break;
        case 9:
            file = "img/9.png";
            break;
        case 10:
            file = "img/10.png";
            break;
        case 11:
            file = "img/11.png";
            break;
        case 12:
            file = "img/12.png";
            break;
        case 13:
            file = "img/13.png";
            break;
        case 14:
            file = "img/14.png";
            break;
        case 15:
            file = "img/15.png";
            break;
        case 16:
            file = "img/16.png";
            break;
        case 17:
            file = "img/17.png";
            break;
        case 18:
            file = "img/18.png";
            break;
        case 19:
            file = "img/19.png";
            break;
        case 20:
            file = "img/20.png";
            break;
        case 21:
            file = "img/21.png";
            break;
        case 22:
            file = "img/22.png";
            break;
        case 23:
            file = "img/23.png";
            break;
        case 24:
            file = "img/24.png";
            break;
        case 25:
            file = "img/25.png";
            break;
        case 26:
            file = "img/26.png";
            break;
        case 27:
            file = "img/27.png";
            break;
        case 28:
            file = "img/28.png";
            break;
        case 29:
            file = "img/29.png";
            break;
        case 30:
            file = "img/30.png";
            break;
        case 31:
            file = "img/31.png";
            break;
        case 32:
            file = "img/32.png";
            break;
        case 33:
            file = "img/33.png";
            break;
        case 34:
            file = "img/34.png";
            break;
        case 35:
            file = "img/35.png";
            break;
        case 36:
            file = "img/36.png";
            break;
        case 37:
            file = "img/37.png";
            break;
        case 38:
            file = "img/38.png";
            break;
        case 39:
            file = "img/39.png";
            break;
        case 40:
            file = "img/40.png";
            break;
        case 41:
            file = "img/41.png";
            break;
        case 42:
            file = "img/42.png";
            break;
        case 43:
            file = "img/43.png";
            break;
        case 44:
            file = "img/44.png";
            break;
        case 45:
            file = "img/45.png";
            break;
        case 46:
            file = "img/46.png";
            break;
        case 47:
            file = "img/47.png";
            break;
        case 48:
            file = "img/48.png";
            break;
        case 49:
            file = "img/49.png";
            break;
        case 50:
            file = "img/50.png";
            break;
        case 51:
            file = "img/52.png";
            break;
        case 52:
            file = "img/52.png";
            break;
        case 53:
            file = "img/53.png";
            break;
        case 54:
            file = "img/54.png";
            break;
        case 55:
            file = "img/55.png";
            break;
        case 56:
            file = "img/56.png";
            break;
        case 57:
            file = "img/57.png";
            break;
        case 58:
            file = "img/58.png";
            break;
        case 59:
            file = "img/59.png";
            break;
        case 60:
            file = "img/60.png";
            break;
        case 61:
            file = "img/61.png";
            break;
        case 62:
            file = "img/62.png";
            break;
        case 63:
            file = "img/63.png";
            break;
        case 64:
            file = "img/64.png";
            break;
        case 65:
            file = "img/65.png";
            break;
        case 66:
            file = "img/66.png";
            break;
        case 67:
            file = "img/67.png";
            break;
        case 68:
            file = "img/68.png";
            break;
        case 69:
            file = "img/69.png";
            break;
        case 70:
            file = "img/70.png";
            break;
        case -1:
            file = "img/-1.png";
            break;
        case -2:
            file = "img/-2.png";
            break;
        case -3:
            file = "img/-3.png";
            break;
        case -4:
            file = "img/-4.png";
            break;
        case -5:
            file = "img/-5.png";
            break;
        case -6:
            file = "img/-6.png";
            break;
        case -7:
            file = "img/-7.png";
            break;
        case -8:
            file = "img/-8.png";
            break;
        case -9:
            file = "img/-9.png";
            break;
        case -10:
            file = "img/-10.png";
            break;
        case -11:
            file = "img/-11.png";
            break;
        case -12:
            file = "img/-12.png";
            break;
        case -13:
            file = "img/-13.png";
            break;
        case -14:
            file = "img/-14.png";
            break;
        case -15:
            file = "img/-15.png";
            break;
        case -16:
            file = "img/-16.png";
            break;
        case -17:
            file = "img/-17.png";
            break;
        case -18:
            file = "img/-18.png";
            break;
        case -19:
            file = "img/-19.png";
            break;
        case -20:
            file = "img/-20.png";
            break;
        case -21:
            file = "img/-21.png";
            break;
        case -22:
            file = "img/-22.png";
            break;
        case -23:
            file = "img/-23.png";
            break;
        case -24:
            file = "img/-24.png";
            break;
        case -25:
            file = "img/-25.png";
            break;
        case -26:
            file = "img/-26.png";
            break;
        case -27:
            file = "img/-27.png";
            break;
        case -28:
            file = "img/-28.png";
            break;
        case -29:
            file = "img/-29.png";
            break;
        case -30:
            file = "img/-30.png";
            break;
        case -31:
            file = "img/-31.png";
            break;
        case -32:
            file = "img/-32.png";
            break;
        case -33:
            file = "img/-33.png";
            break;
        case -34:
            file = "img/-34.png";
            break;
        case -35:
            file = "img/-35.png";
            break;
        case -36:
            file = "img/-36.png";
            break;
        case -37:
            file = "img/-37.png";
            break;
        case -38:
            file = "img/-38.png";
            break;
        case -39:
            file = "img/-39.png";
            break;
        case -40:
            file = "img/-40.png";
            break;
        case -41:
            file = "img/-41.png";
            break;
        case -42:
            file = "img/-42.png";
            break;
        case -43:
            file = "img/-43.png";
            break;
        case -44:
            file = "img/-44.png";
            break;
        case -45:
            file = "img/-45.png";
            break;
        case -46:
            file = "img/-46.png";
            break;
        case -47:
            file = "img/-47.png";
            break;
        case -48:
            file = "img/-48.png";
            break;
        case -49:
            file = "img/-49.png";
            break;
        case -50:
            file = "img/-50.png";
            break;
        case -51:
            file = "img/-52.png";
            break;
        case -52:
            file = "img/-52.png";
            break;
        case -53:
            file = "img/-53.png";
            break;
        case -54:
            file = "img/-54.png";
            break;
        case -55:
            file = "img/-55.png";
            break;
        case -56:
            file = "img/-56.png";
            break;
        case -57:
            file = "img/-57.png";
            break;
        case -58:
            file = "img/-58.png";
            break;
        case -59:
            file = "img/-59.png";
            break;
        case -60:
            file = "img/-60.png";
            break;
        case -61:
            file = "img/-61.png";
            break;
        case -62:
            file = "img/-62.png";
            break;
        case -63:
            file = "img/-63.png";
            break;
        case -64:
            file = "img/-64.png";
            break;
        case -65:
            file = "img/-65.png";
            break;
        case -66:
            file = "img/-66.png";
            break;
        case -67:
            file = "img/-67.png";
            break;
        case -68:
            file = "img/-68.png";
            break;
        case -69:
            file = "img/-69.png";
            break;
        case -70:
            file = "img/-70.png";
            break;
    };
    loadImage(file,x.col+20, x.row+15);
}

void drawBoad(){ 
    for(int i=0; i<=11; i++){
        initImage(cell[i]);
    }
    initImage(scoresA);
    initImage(scoresB);
    SDL_UpdateWindowSurface( window );
}

void nhap(){
    if( e.type != SDL_MOUSEBUTTONDOWN )
        return;    
    SDL_MouseButtonEvent mouse = e.button;
      loca = mouse.x / 100,
        kiem = mouse.y / 100;
    if( mouse.button == SDL_BUTTON_LEFT )
        dir = left;
    if( mouse.button == SDL_BUTTON_RIGHT )
        dir = right;
    if( loca == 0 || loca == 6)
        return;
}

void luotA(int &state){
    if ( kiem != state )
        return;
    int i = loca;
    int oChuyen;
    diChuyenA(i, oChuyen, state);
}

void luotB(int &state){
    if( kiem != state )
        return;
    dir = chuyenHuong();
    int i = 12 - loca;
    int oChuyen;
    diChuyenB(i, oChuyen, state);
}

void diChuyenA(int &i, int &ochuyen, int &state){
    ochuyen = cell[i].value;
    if( i == 0 || i == 6 || cell[i].value == 0){
        daiQuanB();
        if( ! ketThuc() ){
            state = 1;
            return;
        } else {
            ketQua(scoresA, scoresB, cell);
            return;
        }
    } else {
        cell[i].value = 0;
        if( dir == left ){
            chuyenTrai(i, ochuyen);
            if( i == 0 )
                i = 11;
            else i--;
            tinhDiemTrai(i, scoresA.value);
        } else {
            chuyenPhai(i, ochuyen);
            if( i == 11 )
                i = 0;
            else i++;
            tinhDiemPhai(i, scoresA.value);
        }
        drawBoad();
        diChuyenA(i, ochuyen, state);
    }
}
void diChuyenB(int &i, int &ochuyen, int &state){
    ochuyen = cell[i].value;
    if( i == 0 || i == 6 || cell[i].value == 0 ){
        daiQuanA();
        if( ! ketThuc() ){
            state = 0;
            return;
        } else {
            ketQua(scoresA, scoresB, cell);
            return;
        }
    } else {
        cell[i].value = 0;
        if( dir == left ){
            chuyenTrai(i, ochuyen);
            if( i == 0 )
                i = 11;
            else i--;
            tinhDiemTrai(i, scoresB.value);
        } else {
            chuyenPhai(i, ochuyen);
            if( i == 11 )
                i = 0;
            else i++;
            tinhDiemPhai(i, scoresB.value);
        }
        drawBoad();
        diChuyenB(i, ochuyen, state);
    }   
}
void chuyenTrai(int &u, int &oChuyen){
    while( oChuyen != 0 ){
        if( u > 0 ){
            u--; oChuyen--;cell[u].value++;
        } else {
            u = 12;
            chuyenTrai(u, oChuyen);
        }
    }
}
void chuyenPhai(int &v, int &oChuyen){
    while( oChuyen != 0 ){
        if( v < 11 ){
            v++; oChuyen--;cell[v].value++;
        } else {
            v = -1;
            chuyenPhai(v, oChuyen);
        }
    }
}
void tinhDiemPhai(int i, int &x){
    if( i == 11 ){
        if( cell[i].value == 0 && cell[0].value != 0 ){
            x += cell[0].value;
            cell[0].value = 0;
        }
    }
    else {
        if( cell[i].value == 0 && cell[i+1].value != 0 ){
            x += cell[i+1].value;
            cell[i+1].value = 0;
        }
    }
}
void tinhDiemTrai(int i, int &x){
    if( cell[i].value == 0 &&  cell[i-1].value != 0 ){
        x += cell[i-1].value;
        cell[i-1].value = 0;
    }
}
bool ketThuc(){
    if( cell[0].value == 0 && cell[6].value == 0  )
        return true;
    return false;
}
void ketQua(Cell A, Cell B, Cell *cell){
    if( A.value + cell[1].value +cell[2].value + cell[3].value + cell[4].value + cell[5].value
        == B.value + cell[7].value + cell[8].value+ cell[9].value + cell[10].value + cell[11].value){
        loadBackground("hoa.png");
        return;
    } else {
        if( A.value + cell[1].value +cell[2].value + cell[3].value + cell[4].value + cell[5].value
            > B.value + cell[7].value + cell[8].value+ cell[9].value + cell[10].value + cell[11].value){
            loadBackground("aThang.png");
            return;
        } else
        {
            loadBackground("bThang.png");
            return;
        }
    }
}
Directions chuyenHuong(){
    if( dir == left )
        return right;
    return left;
}
void daiQuanA(){
    if( cell[1].value == 0 && cell[2].value == 0 &&
        cell[3].value == 0 && cell[4].value == 0 &&  cell[5].value == 0 ){
        for(int i=1; i<=5; i++){
            cell[i].value = 1;
        }
        scoresA.value = scoresA.value - 5;
        SDL_Delay(2000);
        drawBoad();
    }
}
void daiQuanB(){
    if( cell[7].value == 0 && cell[8].value == 0 &&
        cell[9].value == 0 && cell[10].value == 0 &&  cell[11].value == 0 ){
        for(int i=7; i<=11; i++){
            cell[i].value = 1;
        }
        scoresB.value = scoresB.value - 5;
        SDL_Delay(2000);
        drawBoad();
    }
}
void game(int &x){
    nhap();
        if( x == 0 ){
            luotA(x);
        } else {
            luotB(x);
        }
}
