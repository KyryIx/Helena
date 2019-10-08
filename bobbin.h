#ifndef BOBBIN_H
#define BOBBIN_H

#include <string>

class Bobbin{

	private:
		unsigned int id;
		std::string type;
		double width;
		double length;
		double height;
	
	public:
		Bobbin(){
            this->id     = 0;
            this->type   = "padrao";
            this->width  = 0.0;
            this->length = 0.0;
            this->height = 0.0;
		}

        void setId( unsigned int id ){
            this->id = id;
		}

		unsigned int getId(){
            return this->id;
		}

		void setType( std::string type="padrao" ){
            this->type = type;
		}

		std::string getType(){
            return this->type;
		}

		void setWidth( double width ){
            this->width = width;
		}

		double getWidth(){
            return this->width;
		}

		void setLength( double length ){
            this->length = length;
		}

		double getLength(){
            return this->length;
		}

		void setHeight( double height ){
            this->height = height;
		}

		double getHeight(){
            return this->height;
		}

		double getArea(){
            return this->getWidth() * this->getLength();
		}

		double getVolume(){
            return this->getWidth() * this->getLength() * this->getHeight();
		}

		std::string toString(){
			std::string txt = "";
            txt = txt + "Bobbin ID: "     + std::to_string( this->getId() )     + "\n";
            txt = txt + "Bobbin Type: "   + this->getType()                     + "\n";
            txt = txt + "Bobbin Width: "  + std::to_string( this->getWidth() )  + " mm\n";
            txt = txt + "Bobbin Length: " + std::to_string( this->getLength() ) + " mm\n";
            txt = txt + "Bobbin Height: " + std::to_string( this->getHeight() ) + " mm\n";
            txt = txt + "Bobbin Area: "   + std::to_string( this->getArea() )   + " mm*mm\n";
            txt = txt + "Bobbin Volume: " + std::to_string( this->getVolume() ) + " mm*mm*mm";
			return txt;
		}

        std::string toHTML(){
            std::string txt = "";
            txt = txt + "<table align=\"center\">\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin ID:</td><td><b>" + std::to_string( this->getId() ) + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Type:</td><td><b>" + this->getType() + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Width:</td><td><b>" + std::to_string( this->getWidth() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Length:</td><td><b>" + std::to_string( this->getLength() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Height:</td><td><b>" + std::to_string( this->getHeight() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Area:</td><td><b>" + std::to_string( this->getArea() )   + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Volume:</td><td><b>" + std::to_string( this->getVolume() ) + " mm<sup>3</sup></b></td></tr>\n";
            txt = txt + "</table>";
            return txt;
        }
};

#endif // BOBBIN_H
