attribute vec4 position; 
attribute vec4 inputTextureCoordinate;

varying vec2 textureCoordinate;

precision mediump float;
uniform float overTurn;

void main()
{
gl_Position = position;
    if (overTurn>0.0) {
        textureCoordinate = vec2(inputTextureCoordinate.x,overTurn-inputTextureCoordinate.y);
    }
    else
        textureCoordinate = vec2(inputTextureCoordinate.x,inputTextureCoordinate.y);
}