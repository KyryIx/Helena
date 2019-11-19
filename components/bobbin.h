#ifndef BOBBIN_H
#define BOBBIN_H

#include <string>

class Bobbin{

	private:
		unsigned int id;
		std::string type;
        std::string code;
        std::string provider;
		double width;
		double length;
		double height;
	
	public:
		Bobbin(){
            this->id       = 0;
            this->type     = "";
            this->code     = "";
            this->provider = "";
            this->width    = 0.0;
            this->length   = 0.0;
            this->height   = 0.0;
		}

        void setId( unsigned int id ){
            this->id = id;
		}

        unsigned int getId() const{
            return this->id;
		}

        void setType( std::string type ){
            this->type = type;
		}

        std::string getType() const{
            return this->type;
		}

        void setCode( std::string code ){
            this->code = code;
        }

        std::string getCode() const{
            return this->code;
        }

        void setProvider( std::string provider ){
            this->provider = provider;
        }

        std::string getProvider() const{
            return this->provider;
        }

		void setWidth( double width ){
            this->width = width;
		}

        double getWidth() const{
            return this->width;
		}

		void setLength( double length ){
            this->length = length;
		}

        double getLength() const{
            return this->length;
		}

		void setHeight( double height ){
            this->height = height;
		}

        double getHeight() const{
            return this->height;
		}

        double getArea() const{
            return this->getWidth() * this->getLength();
		}

        double getVolume() const{
            return this->getWidth() * this->getLength() * this->getHeight();
		}

        std::string toString() const{
			std::string txt = "";
            txt = txt + "Bobbin ID:       " + std::to_string( this->getId() )     + "\n";
            txt = txt + "Bobbin Type:     " + this->getType()                     + "\n";
            txt = txt + "Bobbin Code:     " + this->getCode()                     + "\n";
            txt = txt + "Bobbin Provider: " + this->getProvider()                 + "\n";
            txt = txt + "Bobbin Width:    " + std::to_string( this->getWidth() )  + " mm\n";
            txt = txt + "Bobbin Length:   " + std::to_string( this->getLength() ) + " mm\n";
            txt = txt + "Bobbin Height:   " + std::to_string( this->getHeight() ) + " mm\n";
            txt = txt + "Bobbin Area:     " + std::to_string( this->getArea() )   + " mm*mm\n";
            txt = txt + "Bobbin Volume:   " + std::to_string( this->getVolume() ) + " mm*mm*mm";

			return txt;
		}

        std::string toHTML() const{
            std::string txt = "";
            txt = txt + "<table align=\"center\" class=\"bobbin\" width=\"100%\">\n";
            txt = txt + "\t<tr><td align=\"right\" width=\"50%\">Bobbin ID:</td><td><b>" + std::to_string( this->getId() )     + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Type:</td><td><b>"             + this->getType()                     + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Code:</td><td><b>"             + this->getCode()                     + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Provider:</td><td><b>"         + this->getProvider()                 + "</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Width:</td><td><b>"            + std::to_string( this->getWidth() )  + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Length:</td><td><b>"           + std::to_string( this->getLength() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Height:</td><td><b>"           + std::to_string( this->getHeight() ) + " mm</b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Area:</td><td><b>"             + std::to_string( this->getArea() )   + " mm<sup>2</sup></b></td></tr>\n";
            txt = txt + "\t<tr><td align=\"right\">Bobbin Volume:</td><td><b>"           + std::to_string( this->getVolume() ) + " mm<sup>3</sup></b></td></tr>\n";
            txt = txt + "</table>";

            return txt;
        }

        std::string toSQL() const{
            std::string txt = "";
            txt = txt + "INSERT INTO bobbins (";
            txt = txt + "code_bobbin, width_bobbin, length_bobbin, ";
            txt = txt + "height_bobbin, type_bobbin, provider_bobbin";
            txt = txt + ") VALUES( ";
            txt = "'" + this->getCode()                     + "', ";
            txt = txt + std::to_string( this->getWidth() )  + ", ";
            txt = txt + std::to_string( this->getLength() ) + ", ";
            txt = txt + std::to_string( this->getHeight() ) + ", ";
            txt = txt + "'" + this->getType()               + "', ";
            txt = txt + "'" + this->getProvider()           + "' )";

            return txt;
        }
};

#endif // BOBBIN_H
