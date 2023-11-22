import processing.video.*;

Capture cam;

void setup()  {
  // 320 240 30
  // println(Capture.list());
  size(640, 480);
  
  cam = new Capture(this);
  cam.start();
}

void draw()  {
  if(cam.available()) {
    cam.read();
  }
  image(cam, 0,0);
}
