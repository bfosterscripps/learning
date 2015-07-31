// supposedly you can mix js and Processing:
// http://processingjs.org/articles/jsQuickStart.html#mixingjsandprocessing
void setup() {
  size(640,360);
  var location = constructPVector(100, 100, 100),
  velocity = constructPVector(2.5, 5, 2.5);
}

void draw() {
  background(255);

  location.add(velocity);

  if ((location.getX() > width) || (location.getX() < 0)) {
    velocity.setX(velocity.getX() * -1);
  }
  if ((location.getY() > height) || (location.getY() < 0)) {
    velocity.setY(velocity.getY() * -1);
  }
  if ((location.getZ() > height) || (location.getZ() < 0)) {
    velocity.setZ(velocity.getZ() * -1);
  }


  stroke(0);
  fill(175);
  ellipse(location.getX(), location.getY(),16,16);
}
