//
// Created by Cjsah on 2024/7/10.
//

#include "config.h"

Genshin::Genshin() : Genshin(false) {}

Genshin::Genshin(const bool showLastLevel) {
    this->showLastLevel = showLastLevel;
}

Genshin Genshin::fromJson(const QJsonObject &json) {
    const bool showLastLevel = json.value("showLastLevel").toBool(false);
    return Genshin(showLastLevel);
}

QJsonObject Genshin::toJson() const {
    QJsonObject json;
    json.insert("showLastLevel", this->showLastLevel);
    return json;
}

void Genshin::setShowLastLevel(const bool show) {
    this->showLastLevel = show;
}

bool Genshin::isShowLastLevel() const {
    return this->showLastLevel;
}

StarRail::StarRail(): StarRail (false){}

StarRail::StarRail(const bool showLastLevel) {
    this->showLastLevel = showLastLevel;
}

StarRail StarRail::fromJson(const QJsonObject &json) {
    const bool showLastLevel = json.value("showLastLevel").toBool(false);
    return StarRail(showLastLevel);
}

QJsonObject StarRail::toJson() const {
    QJsonObject json;
    json.insert("showLastLevel", this->showLastLevel);
    return json;
}

void StarRail::setShowLastLevel(const bool show) {
    this->showLastLevel = show;
}

bool StarRail::isShowLastLevel() const {
    return this->showLastLevel;
}

Config::Config(const Genshin &genshin, const StarRail &starRail) {
    this->genshin = genshin;
    this->starRail = starRail;
}

const Genshin &Config::getGenshin() {
    return this->genshin;
}

const StarRail &Config::getStarRail() {
    return this->starRail;
}

Config Config::fromJson(const QJsonObject &json) {
    const QJsonObject &genshinJson = json.value("genshin").toObject();
    const QJsonObject &starRailJson = json.value("starrail").toObject();
    const Genshin &genshin = Genshin::fromJson(genshinJson);
    const StarRail &starRail = StarRail::fromJson(starRailJson);
    return Config(genshin, starRail);
}

QJsonObject Config::toJson() const {
    QJsonObject json;
    const QJsonObject &genshinJson = genshin.toJson();
    const QJsonObject &starRailJson = starRail.toJson();
    json.insert("genshin", genshinJson);
    json.insert("starrail", starRailJson);
    return json;
}
