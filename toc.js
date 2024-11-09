// Populate the sidebar
//
// This is a script, and not included directly in the page, to control the total size of the book.
// The TOC contains an entry for each page, so if each page includes a copy of the TOC,
// the total size of the page becomes O(n**2).
class MDBookSidebarScrollbox extends HTMLElement {
    constructor() {
        super();
    }
    connectedCallback() {
        this.innerHTML = '<ol class="chapter"><li class="chapter-item expanded "><a href="230914.html"><strong aria-hidden="true">1.</strong> 基础知识1.1~1.9(1)</a></li><li class="chapter-item expanded "><a href="230921.html"><strong aria-hidden="true">2.</strong> 基础知识1.1~1.9(2)</a></li><li class="chapter-item expanded "><a href="230928.html"><strong aria-hidden="true">3.</strong> 国庆假期作业</a></li><li class="chapter-item expanded "><a href="231007.html"><strong aria-hidden="true">4.</strong> 基础知识2.1~2.7</a></li><li class="chapter-item expanded "><a href="231012.html"><strong aria-hidden="true">5.</strong> 基础知识2.8~分治策略3.5</a></li><li class="chapter-item expanded "><a href="231019.html"><strong aria-hidden="true">6.</strong> 幂乘算法及其应用3.6~4.5选择问题的算法分析</a></li><li class="chapter-item expanded "><a href="231026.html"><strong aria-hidden="true">7.</strong> 动态规划算法的例子5.2~动态规划算法的迭代实现5.5</a></li><li class="chapter-item expanded "><a href="231030.html"><strong aria-hidden="true">8.</strong> 最长公共子序列5.8</a></li><li class="chapter-item expanded "><a href="231106.html"><strong aria-hidden="true">9.</strong> 两个问题</a></li><li class="chapter-item expanded "><a href="231113.html"><strong aria-hidden="true">10.</strong> 贪心法的设计思想4.1~对贪心法得不到最优解情况的处理4.3</a></li><li class="chapter-item expanded "><a href="231120.html"><strong aria-hidden="true">11.</strong> 贪心法</a></li><li class="chapter-item expanded "><a href="231128.html"><strong aria-hidden="true">12.</strong> 回溯算法</a></li><li class="chapter-item expanded "><a href="231204.html"><strong aria-hidden="true">13.</strong> 线性规划</a></li><li class="chapter-item expanded "><a href="231211.html"><strong aria-hidden="true">14.</strong> 网络流算法</a></li><li class="chapter-item expanded "><a href="231219.html"><strong aria-hidden="true">15.</strong> 算法分析与问题的计算复杂度</a></li><li class="chapter-item expanded "><a href="231225.html"><strong aria-hidden="true">16.</strong> NP完全性</a></li><li class="chapter-item expanded "><a href="note-1.html"><strong aria-hidden="true">17.</strong> 基础知识学习笔记</a></li><li class="chapter-item expanded "><a href="note-2.html"><strong aria-hidden="true">18.</strong> 分治算法学习笔记</a></li><li class="chapter-item expanded "><a href="note-3.html"><strong aria-hidden="true">19.</strong> 动态规划学习笔记</a></li><li class="chapter-item expanded "><a href="note-4.html"><strong aria-hidden="true">20.</strong> 贪心法学习笔记</a></li><li class="chapter-item expanded "><a href="note-5.html"><strong aria-hidden="true">21.</strong> 回溯法学习笔记</a></li><li class="chapter-item expanded "><a href="note-6.html"><strong aria-hidden="true">22.</strong> 线性规划学习笔记</a></li><li class="chapter-item expanded "><a href="note-7.html"><strong aria-hidden="true">23.</strong> 网络流算法学习笔记</a></li><li class="chapter-item expanded "><a href="note-8.html"><strong aria-hidden="true">24.</strong> 算法分析和问题的计算复杂度学习笔记</a></li><li class="chapter-item expanded "><a href="note-9.html"><strong aria-hidden="true">25.</strong> NP完全性学习笔记</a></li><li class="chapter-item expanded "><a href="final-exam-points.html"><strong aria-hidden="true">26.</strong> 期末复习重点</a></li><li class="chapter-item expanded "><a href="final-exam-review1.html"><strong aria-hidden="true">27.</strong> 期末复习题（1）</a></li><li class="chapter-item expanded "><a href="final-exam-review2.html"><strong aria-hidden="true">28.</strong> 期末复习题（2）</a></li><li class="chapter-item expanded "><a href="final-exam-review3.html"><strong aria-hidden="true">29.</strong> 分治算法大题</a></li><li class="chapter-item expanded "><a href="final-exam-review4.html"><strong aria-hidden="true">30.</strong> 动态规划大题</a></li><li class="chapter-item expanded "><a href="final-exam-review5.html"><strong aria-hidden="true">31.</strong> 贪心算法大题</a></li><li class="chapter-item expanded "><a href="final-exam-review6.html"><strong aria-hidden="true">32.</strong> 回溯算法大题</a></li><li class="chapter-item expanded "><a href="240115.html"><strong aria-hidden="true">33.</strong> 期末考试回顾</a></li></ol>';
        // Set the current, active page, and reveal it if it's hidden
        let current_page = document.location.href.toString();
        if (current_page.endsWith("/")) {
            current_page += "index.html";
        }
        var links = Array.prototype.slice.call(this.querySelectorAll("a"));
        var l = links.length;
        for (var i = 0; i < l; ++i) {
            var link = links[i];
            var href = link.getAttribute("href");
            if (href && !href.startsWith("#") && !/^(?:[a-z+]+:)?\/\//.test(href)) {
                link.href = path_to_root + href;
            }
            // The "index" page is supposed to alias the first chapter in the book.
            if (link.href === current_page || (i === 0 && path_to_root === "" && current_page.endsWith("/index.html"))) {
                link.classList.add("active");
                var parent = link.parentElement;
                if (parent && parent.classList.contains("chapter-item")) {
                    parent.classList.add("expanded");
                }
                while (parent) {
                    if (parent.tagName === "LI" && parent.previousElementSibling) {
                        if (parent.previousElementSibling.classList.contains("chapter-item")) {
                            parent.previousElementSibling.classList.add("expanded");
                        }
                    }
                    parent = parent.parentElement;
                }
            }
        }
        // Track and set sidebar scroll position
        this.addEventListener('click', function(e) {
            if (e.target.tagName === 'A') {
                sessionStorage.setItem('sidebar-scroll', this.scrollTop);
            }
        }, { passive: true });
        var sidebarScrollTop = sessionStorage.getItem('sidebar-scroll');
        sessionStorage.removeItem('sidebar-scroll');
        if (sidebarScrollTop) {
            // preserve sidebar scroll position when navigating via links within sidebar
            this.scrollTop = sidebarScrollTop;
        } else {
            // scroll sidebar to current active section when navigating via "next/previous chapter" buttons
            var activeSection = document.querySelector('#sidebar .active');
            if (activeSection) {
                activeSection.scrollIntoView({ block: 'center' });
            }
        }
        // Toggle buttons
        var sidebarAnchorToggles = document.querySelectorAll('#sidebar a.toggle');
        function toggleSection(ev) {
            ev.currentTarget.parentElement.classList.toggle('expanded');
        }
        Array.from(sidebarAnchorToggles).forEach(function (el) {
            el.addEventListener('click', toggleSection);
        });
    }
}
window.customElements.define("mdbook-sidebar-scrollbox", MDBookSidebarScrollbox);
