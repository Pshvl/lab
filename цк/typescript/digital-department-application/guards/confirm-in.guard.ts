import { ActivatedRouteSnapshot, RouterStateSnapshot } from "@angular/router";

export const confirmInGuard= (route: ActivatedRouteSnapshot, state: RouterStateSnapshot)=>{
    return confirm("Вы точно хотите перейти на эту страницу?");
}