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
        Filter * buildFilter(filterDefinition) const {
            switch (filterDefinition[0]) {
                case 'A': return new AZFilter;
                case 'a': return new azFilter;
                case '0': return new FilterDigitsOneToNine;
            }

            return nullptr;
        }
};

#endif
