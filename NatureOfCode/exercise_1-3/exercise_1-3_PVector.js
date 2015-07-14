// 20150714, Brandon Foster
// - decided to convert the Java Processing example into javascript

var constructPVector = function(startX, startY, startZ){
  var that = {},
      isError = false,
      floatX = '0.0',
      floatY = '0.0',
      floatZ = '0.0',
      add = function(vectorObj){
        floatX += vectorObj.getX();
        floatY += vectorObj.getY();
        floatZ += vectorObj.getZ();
      },
      getX = function(){
        return floatX;
      },
      getY = function(){
        return floatY;
      },
      getZ = function(){
        return floatZ;
      },
      setX = function(x){
        floatX = x;
        return floatX;
      },
      setY = function(y){
        floatY = y;
        return floatY;
      },
      setZ = function(z){
        floatZ = z;
        return floatZ;
      };

  that.add = add;
  that.getX = getX;
  that.getY = getY;
  that.getZ = getZ;
  that.setX = setX;
  that.setY = setY;
  that.setZ = setZ;

  if(typeof startX !== 'undefined'){
    that.setX(startX);
  } else{
    isError = true;
    console.error("Parameter passed to vector constructor for X is undefined!");
  }
  if(typeof startY !== 'undefined'){
    that.setY(startY);
  }else {
    isError = true;
    console.error("Parameter passed to vector constructor for Y is undefined!");
  }
  if(typeof startZ !== 'undefined'){
    that.setZ(startZ);
  }else {
    isError = true;
    console.error("Parameter passed to vector constructor for Z is undefined!");
  }

  if(!isError){
    return that;
  }
};

// just some tests :-)
// var examplePVector = constructPVector(100, 100, 100);
//
// examplePVector.setX(200);
// examplePVector.setY(500);
// examplePVector.setZ(50);
//
// console.log('X: ' + examplePVector.getX());
// console.log('Y: ' + examplePVector.getY());
// console.log('Z: ' + examplePVector.getZ());
