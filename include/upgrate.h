// -- Escena para elegir las mejoras --

#ifndef UPGRATE_H
#define UPGRATE_H

class Upgrate {
    private:
        const char *basic_upgrate = "[1] Mejora basica [3 puntos]";
        const char *normal_upgrate = "[2] Mejora normal [6 puntos]";
        const char *pro_upgrate = "[3] Mejora pro [9 puntos]";
        const char *skip_upgrate = "[4] Saltar mejoras";
        int font_size = 20;

    public:
        Upgrate();
        void basicUpgrate(void);
        void normalUpgrate(void);
        void bestUpgrate(void);
        int update(void);
        void draw(void);
};

#endif
