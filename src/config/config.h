//
// Created by Cjsah on 2024/7/10.
//

#ifndef CALC_TABLE_CONFIG_H
#define CALC_TABLE_CONFIG_H

#include <QJsonObject>

class Genshin {
public:
    Genshin();
    explicit Genshin(bool showLastLevel);
    bool isShowLastLevel() const;
    void setShowLastLevel(bool show);
    static Genshin fromJson(const QJsonObject &json);
    QJsonObject toJson() const;
private:
    bool showLastLevel;
};

class StarRail {
public:
    StarRail();
    explicit StarRail(bool showLastLevel);
    bool isShowLastLevel() const;
    void setShowLastLevel(bool show);
    static StarRail fromJson(const QJsonObject &json);
    QJsonObject toJson() const;
private:
    bool showLastLevel{};
};

class Config {
public:
    explicit Config(const Genshin &genshin, const StarRail &starRail);
    const Genshin &getGenshin();
    const StarRail &getStarRail();
    static Config fromJson(const QJsonObject &json);
    QJsonObject toJson() const;
private:
    Genshin genshin;
    StarRail starRail;
};

#endif //CALC_TABLE_CONFIG_H
