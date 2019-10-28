#ifndef LAMINA_H
#define LAMINA_H

#include <string>

class Lamina{

	private:
		unsigned int id;
		std::string type;
        double width;
		double windowArea;
		double weight;
        double thicknessPercent;
	
	public:
		Lamina(){
            this->id               = 0;
            this->type             = "padrao";
            this->width            = 0.0;
            this->windowArea       = 0.0;
            this->weight           = 0.0;
            this->thicknessPercent = 0.0;
		}

        void setId( unsigned int id ){
            this->id = id;
		}

        unsigned int getId() const{
            return this->id;
		}

        void setType( std::string type="padrao" ){
            this->type = type;
		}

        std::string getType() const{
            return this->type;
		}

        void setWidth( double width ){
            this->width = width;
		}

        double getWidth() const{
            return this->width;
		}

		void setWindowArea( double windowArea ){
            this->windowArea = windowArea;
		}

        double getWindowArea() const{
            return this->windowArea;
		}

		void setWeight( double weight ){
            this->weight = weight;
		}

        double getWeight() const{
            return this->weight;
		}

        void setThicknessPercent( double thicknessPercent ){
            this->thicknessPercent = thicknessPercent;
        }

        double getThicknessPercent() const{
            return this->thicknessPercent;
        }

        std::string toString() const{
			std::string txt = "";
            txt = txt + "Lamina ID:                " + std::to_string( this->getId() )         + "\n";
            txt = txt + "Lamina Type:              " + this->getType()                         + "\n";
            txt = txt + "Lamina Width :            " + std::to_string( this->getWidth() )      + " mm\n";
            txt = txt + "Lamina Window Area:       " + std::to_string( this->getWindowArea() ) + " mm*mm\n";
            txt = txt + "Lamina Weight:            " + std::to_string( this->getWeight() )     + " kg/cm\n";
            txt = txt + "Lamina Thickness Percent: " + std::to_string( this->getThicknessPercent() )     + " %";

			return txt;
		}

        std::string toHTML() const{
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"lamina\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Lamina ID:</td><td><b>"  + std::to_string( this->getId() )               + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Lamina Type:</td><td><b>"              + this->getType()                               + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Lamina Width:</td><td><b>"             + std::to_string( this->getWidth() )            + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Lamina Window Area:</td><td><b>"       + std::to_string( this->getWindowArea() )       + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Lamina Weight:</td><td><b>"            + std::to_string( this->getWeight() )           + " kg/cm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Lamina Thickness Percent:</td><td><b>" + std::to_string( this->getThicknessPercent() ) + " %</b></td></tr>\n";
            txt = txt + "</table>";

            return txt;
        }

        std::string toSQL() const{
            std::string txt = "";
            txt = txt + "INSERT INTO laminas (";
            txt = txt + "width_lamina, area_lamina, weight_lamina, thicknessPercent_lamina, type_lamina";
            txt = txt + ") VALUES( ";
            txt = txt + std::to_string( this->getWidth() )            + ", ";
            txt = txt + std::to_string( this->getWindowArea() )       + ", ";
            txt = txt + std::to_string( this->getWeight() )           + ", ";
            txt = txt + std::to_string( this->getThicknessPercent() ) + ", ";
            txt = txt + "'" + this->getType()                         + "' )";

            return txt;
        }
};

#endif // LAMINA_H
