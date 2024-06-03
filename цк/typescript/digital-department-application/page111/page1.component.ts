import { Component } from '@angular/core';

@Component({
  selector: 'app-page1',
  template: `
    <h1 style="font-style: italic;" class="page-header">Страница 1</h1>
    <div class="gallery">
      <img src="1.jpg" alt="Photo 1">
      <p>Описание фото 1</p>

      <img src="2.jpg" alt="Photo 2">
      <p>Описание фото 2</p>

      <img src="3.jpg" alt="Photo 3">
      <p>Описание фото 3</p>
    </div>
  `,
  styles: [`
    .gallery {
      display: flex;
      flex-direction: column;
      align-items: center;
    }
    img {
      max-width: 100%;
    }
  `]
})
export class Page1Component {}