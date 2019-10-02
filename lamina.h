#include <string>

class Lamina{

	private:
		unsigned int id;
		std::string type;
        double width;
		double windowArea;
		double weight;
	
	public:
		Lamina(){
            this->id         = 0;
            this->type       = "simples";
            this->width      = 0.0;
            this->windowArea = 0.0;
            this->weight     = 0.0;
		}

        void setId( unsigned int id ){
            this->id = id;
		}

		unsigned int getId(){
            return this->id;
		}

        void setType( std::string type="simples" ){
            this->type = type;
		}

		std::string getType(){
            return this->type;
		}

        void setThickness( double width ){
            this->width = width;
		}

        double getWidth(){
            return this->width;
		}

		void setWindowArea( double windowArea ){
            this->windowArea = windowArea;
		}

		double getWindowArea(){
            return this->windowArea;
		}

		void setWeight( double weight ){
            this->weight = weight;
		}

		double getWeight(){
            return this->weight;
		}

		std::string toString(){
			std::string txt = "";
            txt = txt + "Lamina ID: "          + std::to_string( this->getId() )         + "\n";
            txt = txt + "Lamina Type: "        + this->getType()                         + "\n";
            txt = txt + "Lamina Thickness: "   + std::to_string( this->getWidth() )      + " mm\n";
            txt = txt + "Lamina Window Area: " + std::to_string( this->getWindowArea() ) + " mm*mm\n";
            txt = txt + "Lamina Weight: "      + std::to_string( this->getWeight() )     + " kg/cm";
			return txt;
		}
};
