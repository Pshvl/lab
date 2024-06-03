import { Component, OnInit } from '@angular/core';
import { filter } from 'rxjs';
import { DataService, Dish } from 'src/app/core/services/data.service';

@Component({
  selector: 'app-page3',
  templateUrl: './page3.component.html',
  styleUrls: ['./page3.component.css']
})
export class Page3Component implements OnInit {

  dishes: Dish[]=[];


  constructor(private dataService: DataService) {

  }

  ngOnInit(): void {
    this.dataService.getData()
    .pipe(
      filter(data => data!=null),

    )
    .subscribe((dishes)=>{
      this.dishes=dishes;
    })
  }
}
