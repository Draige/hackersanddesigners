// Face It
// ITP Fall 2013
// Daniel Shiffman

// Now we need the video library
import processing.video.*;

// Import the library
import gab.opencv.*;

// We need Java rectangles
import java.awt.Rectangle;

// Library object
OpenCV opencv;

// Capture object
Capture cam;

// Array of faces found
Rectangle[] faces;

//create output to txt
PrintWriter output;

int sizeWidth = 320;
int sizeHeight = 240;
int thresholdHeight = 90;
int thresholdFaceWidth = 100;
int trigger = 0;

void setup() {
  size(sizeWidth, sizeHeight,P2D);
  
  // Start capturing
  cam = new Capture(this, sizeWidth, sizeHeight);
  cam.start();

  // Create the OpenCV object
  opencv = new OpenCV(this, cam.width, cam.height);
  
  // Which "cascade" are we going to use?
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE);  
  //opencv.loadCascade(OpenCV.CASCADE_EYE);  
  //opencv.loadCascade(OpenCV.CASCADE_NOSE); 

  // Create a new file in the sketch directory
  output = createWriter("positions.txt"); 
    
}

// New images from camera
void captureEvent(Capture cam) {
  cam.read();
}

void draw() {
  
  background(0);
  
  // We have to always "load" the camera image into OpenCV 
  opencv.loadImage(cam);
  
  // Detect the faces
  faces = opencv.detect();
  
  // Draw the video
  image(cam, 0, 0);

  // If we find faces, draw them!
  if (faces != null) {
    for (int i = 0; i < faces.length; i++) {
      strokeWeight(2);
      stroke(255,0,0);
      noFill();
      rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);

      //println(faces[0].y);
      //println (faces[0].width);
      if (faces[0].y <= thresholdHeight && faces[0].width <= thresholdFaceWidth ) {
        randomErrorPos();
      }
      if (faces[0].y >= thresholdHeight || faces[0].width >= thresholdFaceWidth ) {
        randomErrorNeg();
      }
    }

  }
}

void randomErrorPos() {
  if (trigger == 1){
    trigger = 0;
    // Get a random element from an array
    String[] positivePhrases = { 
      "Sitting position neatly adapted.",
      "hey sweety, cute back.",
      "A healty siting posture is FUN.",
      "Well done, your back looks happy"
    };
    int index = int(random(positivePhrases.length));  // Same as int(random(4))
    output = createWriter("positions.txt"); 
    output.println(positivePhrases[index]);  // Prints one of the four words
    println(positivePhrases[index]);
    //println ("reset trigger to 0");
    output.flush(); // Writes the remaining data to the file
    output.close(); // Finishes the file
    //setup();
  }
}

void randomErrorNeg() {
  if (trigger == 0){
    trigger = 1;
    // Get a random element from an array
    String[] negativePhrases = { 
      "Good posture prolongs your lifespan.",
      "A good seating position also helps in the electric chair.",
      "The better your posture, the better your work.",
      "The posture of the body itself reveals the state of mind."
    };
    int index = int(random(negativePhrases.length));  // Same as int(random(4));
    output = createWriter("positions.txt"); 
    output.println(negativePhrases[index]);  // Prints one of the four words
    print(negativePhrases[index]);
    println (" TRIGGER");
    output.flush(); // Writes the remaining data to the file
    output.close(); // Finishes the file
    //setup();
  }
  
}

