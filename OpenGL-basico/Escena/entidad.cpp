#include "entidad.h"

void entidad::set_activa() {
    this->activa_ = !this->activa_;
}

void entidad::dibujar() const {
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura_);
    glTranslatef(posicion_.get_x(), posicion_.get_y(), posicion_.get_z());
    glScalef(escala_.get_x(), escala_.get_y(), escala_.get_z());

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(vertex), &vertices_[0].position);
    glNormalPointer(GL_FLOAT, sizeof(vertex), &vertices_[0].normal);
    glTexCoordPointer(2, GL_FLOAT, sizeof(vertex), &vertices_[0].tex_coords);

    glDrawElements(GL_TRIANGLES, indices_.size(), GL_UNSIGNED_INT, indices_.data());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
