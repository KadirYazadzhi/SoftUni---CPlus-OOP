#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

class AZFilter : public Filter {
    protected:
        virtual bool shouldFilterOut(char symbol) const override {
            return (symbol >= 'A' && symbol <= 'Z');
        }
};

class azFilter : public Filter {
    protected:
        virtual bool shouldFilterOut(char symbol) const override {
            return (symbol >= 'a' && symbol <= 'z');
        }
};

class FilterDigitsOneToNine : public Filter {
protected:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol >= '0' && symbol <= '9');
    }
};

class FilterFactory {
    public:
        Filter * buildFilter(std::string& filterDefinition) const {
            switch (filterDefinition[0]) {
                case 'A':
                    return new AZFilter;
                    break;
                case 'a':
                    return new azFilter;
                    break;
                case '0':
                    return new FilterDigitsOneToNine;
                    break;
            }

            return nullptr;
        }
};

#endif
