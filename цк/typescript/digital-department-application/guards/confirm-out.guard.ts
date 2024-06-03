import { ActivatedRouteSnapshot, RouterStateSnapshot } from "@angular/router";

export const confirmOutGuard= (route: ActivatedRouteSnapshot, state: RouterStateSnapshot)=>{
    return confirm("Вы точно хотите уйти с этой страницы?");
}