<h2><a href="https://leetcode.com/problems/maximum-number-that-makes-result-of-bitwise-and-zero/">3125. Maximum Number That Makes Result of Bitwise AND Zero</a></h2><h3>Medium</h3><hr><div>Given an integer <code>n</code>, return the <strong>maximum</strong> integer <code>x</code> such that <code>x &lt;= n</code>, and the bitwise <code>AND</code> of all the numbers in the range <code>[x, n]</code> is 0.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The bitwise <code>AND</code> of <code>[6, 7]</code> is 6.<br>
The bitwise <code>AND</code> of <code>[5, 6, 7]</code> is 4.<br>
The bitwise <code>AND</code> of <code>[4, 5, 6, 7]</code> is 4.<br>
The bitwise <code>AND</code> of <code>[3, 4, 5, 6, 7]</code> is 0.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 9</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p>The bitwise <code>AND</code> of <code>[7, 8, 9]</code> is 0.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 17</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<p>The bitwise <code>AND</code> of <code>[15, 16, 17]</code> is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>15</sup></code></li>
</ul>
</div>