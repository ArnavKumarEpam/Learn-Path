#include<iostream>
#include<memory>

class Texture{
    private:
        std::string name;
    public:
        Texture(const std::string &name) : name(name){
            std::cout<<"[Texture] loading: " <<name<<std::endl;
        }
        ~Texture(){
            std::cout<<"[Texture] unloading: " <<this -> name<<std::endl;
        }
        void render() const { std::cout << "[Texture] Rendering with: " << name << std::endl; }
};

class Shader{
    private:
        std::string name;
    public:
        Shader(const std::string &name) : name(name){
            std::cout<<"[Shader] Compiling: " << name<<std::endl;
        }
        ~Shader(){
            std::cout<<"[Shader] Deleting: " << this -> name<<std::endl;
        }
        void apply() const { std::cout << "[Shader] Applying: " << name << std::endl; }
};

class GameObject{
    private:
        std::unique_ptr<Texture> texture;
        std::shared_ptr<Shader> shader;
    public:
        GameObject(const std::string &textureName, std::shared_ptr<Shader> shaderPtr){
            shader = shaderPtr;
            texture = std::make_unique<Texture>(textureName);
            std::cout<<"[GameObject] created \n";
        }
        ~GameObject(){
            std::cout<<"[GameObject] destroyed \n";
        }
        void draw() const{
            texture -> render();
            shader -> apply();
        }
        void changeTexture(const std::string &newTextureName){
            texture = std::make_unique<Texture> (newTextureName);

        }
};

int main(){
    std::shared_ptr<Shader> defaultLightingShader = std::make_shared<Shader>("BasicLightingShader");
    std::shared_ptr<Shader> postFxShader = std::make_shared<Shader>("GrayscaleFilterShader");
    std::string textureName = "PlayerTexture";
    GameObject player(textureName, defaultLightingShader);
    textureName = "EnemyTexture";
    GameObject enemy(textureName, defaultLightingShader);
    textureName = "BackgroundTexture";
    GameObject background(textureName, postFxShader);
    std::cout << "\n--- Drawing GameObjects ---" << std::endl;
    player.draw();
    enemy.draw();
    background.draw();
    player.changeTexture("PlayerDamagedTexture");
    player.draw();
    std::cout << "\n--- Demonstrate Scope-based Cleanup ---" << std::endl;
{
    std::cout << "Entering a local scope..." << std::endl;
    GameObject temporaryProp("TempPropTexture", defaultLightingShader); // Creates a GameObject`
    temporaryProp.draw();
    std::cout << "Exiting local scope..." << std::endl;
}

}