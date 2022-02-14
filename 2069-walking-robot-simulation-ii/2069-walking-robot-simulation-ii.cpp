class Robot {
public:
    int peri = 0;
    int curr = 0;
    int widd;
    int hei;
    int x=0,y=0;
    int dirx[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    Robot(int width, int height) {
        peri = width*2 + (height-2)*2;
        hei = height;
        widd = width;
    }
    
    void step(int num) {
        num = num%peri;
        if (x == 0 && y == 0 && curr == 0) curr = 3;
        for(int i=0; i<num;){
            if(curr == 4){
                curr = 0;
            }
            if(x+dirx[curr][0] < widd and y+dirx[curr][1]< hei and y+dirx[curr][1]>=0 and x+dirx[curr][0]>=0){
                x = x+dirx[curr][0];
                y = y+dirx[curr][1];
                i++;
            }else{
                curr++;
            }
            if(curr == 4){
                curr = 0;
            }
        }
        return;
    }
    
    vector<int> getPos() {
        vector<int>hash;
        hash.push_back(x);
        hash.push_back(y);
        return hash;
    }
    
    string getDir() {
        cout << curr << endl;
        if(curr==0){
            return "East";
        }else if(curr == 1){
            return "North";
        }else if(curr == 2){
            return "West";
        }
        return "South";
    }
};
